#!/usr/bin/env perl
use v5.36;
use charnames ();

sub EmojiSegmentationCategory ($cp) {
  if ($cp == 0x20E3) {
    return 'COMBINING_ENCLOSING_KEYCAP';
  }
  if ($cp == 0x20E0) {
    return 'COMBINING_ENCLOSING_CIRCLE_BACKSLASH';
  }
  if ($cp == 0x200D) {
    return 'ZWJ';
  }
  if ($cp == 0xFE0E) {
    return 'VS15';
  }
  if ($cp == 0xFE0F) {
    return 'VS16';
  }
  if ($cp == 0x1F3F4) {
    return 'TAG_BASE';
  }
  if ($cp >= 0xE0020 && $cp <= 0xE007E) {
    return 'TAG_SEQUENCE';
  }
  if ($cp == 0xE007F) {
    return 'TAG_TERM';
  }

  my $char = chr $cp;
  if ($char =~ /(?[ \p{Emoji_Modifier_Base=Yes} & \p{Emoji_Presentation=No} ])/x) {
    return 'EMOJI_MODIFIER_BASE_TEXT';
  }
  if ($char =~ /(?[ \p{Emoji_Modifier_Base=Yes} & \p{Emoji_Presentation=Yes} ])/x) {
    return 'EMOJI_MODIFIER_BASE_EMOJI';
  }
  if ($char =~ /(?[ \p{Emoji_Modifier} ])/x) {
    return 'EMOJI_MODIFIER';
  }
  if ($char =~ /(?[ \p{Regional_Indicator} ])/x) {
    return 'REGIONAL_INDICATOR';
  }
  if ($char =~ / [0-9*#] /x) {
    return 'KEYCAP_BASE';
  }
  if ($char =~ /(?[ \p{Emoji_Presentation=Yes} ])/x) {
    return 'EMOJI_EMOJI_PRESENTATION';
  }
  if ($char =~ /(?[ \p{Emoji=Yes} & \p{Emoji_Presentation=No} ])/x) {
    return 'EMOJI_TEXT_PRESENTATION';
  }

  return '0x0000'; # matches ragel any
}

my $TestUnitRx = qr{
  (?(DEFINE)
    (?<CodePoint>         [0-9A-F]{4,6}                        )
    (?<CodePointSequence> (?&CodePoint) (?: \s (?&CodePoint))* )
    (?<Boolean>           (?: true | false )                   )
  )

  \A

            (?<sequence>    (?&CodePointSequence))
    [;] \s* (?<is_emoji>    (?&Boolean))
    [;] \s* (?<has_vs>      (?&Boolean))
    [;] \s* (?<description> [^;]*)

  \z
}x;

while (<DATA>) {
  chomp;
  next unless length;
  next if / \A [#] /x;

  /$TestUnitRx/
    or die qq/Could not parse test unit line: '$_'\n/;

  my @sequence   = map { hex } split /\s/, $+{sequence};
  my @categories = map { EmojiSegmentationCategory($_) } @sequence;
  my $encoded    = pack 'U*', @sequence;

  utf8::encode($encoded);

  my $len = scalar @sequence;
  my $cat = join ",\n    " , @categories;
  my $seq = join " \n    ", map {
    my $hex = sprintf '0x%.4X,', $_;
    sprintf '%-8s // %s', $hex, charnames::viacode($_)
  } @sequence;

printf <<'EOC', $+{description}, $encoded, $seq, $cat, $len, $+{is_emoji}, $+{has_vs};
{
  .description = "%s; Encoded: %s",
  .sequence = {
    %s 
  },
  .categories  = {
    %s
  },
  .length = %d,
  .is_emoji = %s,
  .has_vs = %s
},
EOC
}

__DATA__
# sequence;is_emoji;has_vs;description

# Basic emoji
1F600;true;false;Emoji presentation default
00A9;false;false;Text presentation default (copyright)

# Keycap sequences
0031;false;false;Lone keycap base
0031 FE0E;false;true;Keycap base + VS-15 (no term)
0031 FE0F;true;true;Keycap base + VS-16 (no term)
0023 20E3;true;false;Unqualified keycap
0031 FE0E 20E3;false;true;Keycap + VS-15 + term
002A FE0F 20E3;true;true;Qualified keycap

# Modifier sequences
1F3FB;true;false;Lone emoji modifier (Fitzpatrick)
261D;false;false;Bare modifier base, text default
261D FE0F;true;true;Modifier base (text default) + VS-16
261D 1F3FB;true;false;Modifier base (text default) + skin tone
1F466 1F3FB;true;false;Modifier base (emoji default) + skin tone

# Regional indicators / flags
1F1FA;true;false;Lone regional indicator
1F1FA 1F1F8;true;false;Flag sequence (US)

# Variation selectors
263A FE0E;false;true;Text-default emoji + VS-15
263A FE0F;true;true;Text-default emoji + VS-16
1F600 FE0E;false;true;Emoji-default emoji + VS-15
1F600 FE0F;true;true;Emoji-default emoji + VS-16

# ZWJ sequences
1F468 200D 1F469 200D 1F467;true;false;ZWJ family
1F468 200D 1F469 200D 1F467 200D 1F466;true;false;Long ZWJ family (4 members)
1F468 200D 2764 200D 1F468;true;false;ZWJ couple
1F468 FE0F 200D 1F469;true;false;ZWJ with VS-16 element
1F468 FE0F 200D 1F469 FE0F;true;false;ZWJ with VS-16 on both elements
1F466 1F3FB 200D 1F4BB;true;false;ZWJ after modifier sequence
1F468 1F3FB 200D 1F4BB;true;false;ZWJ technologist with skin tone
263A FE0F 200D 1F469;true;false;VS-16 enables ZWJ continuation

# Tag sequences
1F3F4 E0067 E0062 E0065 E006E E0067 E007F;true;false;Tag sequence (England)
1F3F4 200D 1F600;true;false;TAG_BASE as ZWJ element
1F3F4 FE0F 200D 1F600;true;false;TAG_BASE + VS-16 + ZWJ
1F3F4 FE0E;false;true;TAG_BASE + VS-15
1F3F4 FE0F;true;true;TAG_BASE + VS-16
