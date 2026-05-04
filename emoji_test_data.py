#!/usr/bin/env python3
import regex, unicodedata

# VERSION1 is required for set operations like intersection (&&); the default is VERSION0.
regex.DEFAULT_VERSION = regex.VERSION1

def get_emoji_segmentation_category(cp):
    if cp == 0x20E3: return 'COMBINING_ENCLOSING_KEYCAP'
    if cp == 0x20E0: return 'COMBINING_ENCLOSING_CIRCLE_BACKSLASH'
    if cp == 0x200D: return 'ZWJ'
    if cp == 0xFE0E: return 'VS15'
    if cp == 0xFE0F: return 'VS16'
    if cp == 0x1F3F4: return 'TAG_BASE'
    if 0xE0020 <= cp <= 0xE007E: return 'TAG_SEQUENCE'
    if cp == 0xE007F: return 'TAG_TERM'
    c = chr(cp)
    if regex.match(r'[[\p{Emoji_Modifier_Base}]&&[\P{Emoji_Presentation}]]', c): return 'EMOJI_MODIFIER_BASE_TEXT'
    if regex.match(r'[[\p{Emoji_Modifier_Base}]&&[\p{Emoji_Presentation}]]', c): return 'EMOJI_MODIFIER_BASE_EMOJI'
    if regex.match(r'\p{Emoji_Modifier}', c): return 'EMOJI_MODIFIER'
    if regex.match(r'\p{Regional_Indicator}', c): return 'REGIONAL_INDICATOR'
    if regex.match(r'[0-9*#]', c): return 'KEYCAP_BASE'
    if regex.match(r'\p{Emoji_Presentation}', c): return 'EMOJI_EMOJI_PRESENTATION'
    if regex.match(r'[[\p{Emoji}]&&[\P{Emoji_Presentation}]]', c): return 'EMOJI_TEXT_PRESENTATION'
    return '0x0000'

TestUnitRx = regex.compile(r"""
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
""", regex.X)

def write_test_data():
    for line in DATA.strip().splitlines():
        m = TestUnitRx.match(line)
        if not m:
          if line and not line.startswith('#'):
              raise ValueError(f'Could not parse test unit: {line!r}')
          continue
        seq = [int(x, 16) for x in m.group('sequence').split()]
        cats = [get_emoji_segmentation_category(cp) for cp in seq]
        fmt_seq = "\n    ".join(f"{f'0x{cp:04X},':<8} // {unicodedata.name(chr(cp))}" for cp in seq)
        print(f"""{{
  .description = "{m.group('description')}; Encoded: {"".join(chr(cp) for cp in seq)}",
  .sequence = {{
    {fmt_seq}
  }},
  .categories  = {{
    {",\n    ".join(cats)}
  }},
  .length = {len(seq)},
  .is_emoji = {m.group('is_emoji')},
  .has_vs = {m.group('has_vs')}
}},""")

DATA = """
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
"""
write_test_data()
