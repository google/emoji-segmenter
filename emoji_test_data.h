{
  .description = "Emoji presentation default; Encoded: 😀",
  .sequence = {
    0x1F600, // GRINNING FACE
  },
  .categories  = {
    EMOJI_EMOJI_PRESENTATION
  },
  .length = 1,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Text presentation default (copyright); Encoded: ©",
  .sequence = {
    0x00A9,  // COPYRIGHT SIGN
  },
  .categories  = {
    EMOJI_TEXT_PRESENTATION
  },
  .length = 1,
  .is_emoji = false,
  .has_vs = false
},
{
  .description = "Lone keycap base; Encoded: 1",
  .sequence = {
    0x0031,  // DIGIT ONE
  },
  .categories  = {
    KEYCAP_BASE
  },
  .length = 1,
  .is_emoji = false,
  .has_vs = false
},
{
  .description = "Keycap base + VS-15 (no term); Encoded: 1︎",
  .sequence = {
    0x0031,  // DIGIT ONE
    0xFE0E,  // VARIATION SELECTOR-15
  },
  .categories  = {
    KEYCAP_BASE,
    VS15
  },
  .length = 2,
  .is_emoji = false,
  .has_vs = true
},
{
  .description = "Keycap base + VS-16 (no term); Encoded: 1️",
  .sequence = {
    0x0031,  // DIGIT ONE
    0xFE0F,  // VARIATION SELECTOR-16
  },
  .categories  = {
    KEYCAP_BASE,
    VS16
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = true
},
{
  .description = "Unqualified keycap; Encoded: #⃣",
  .sequence = {
    0x0023,  // NUMBER SIGN
    0x20E3,  // COMBINING ENCLOSING KEYCAP
  },
  .categories  = {
    KEYCAP_BASE,
    COMBINING_ENCLOSING_KEYCAP
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Keycap + VS-15 + term; Encoded: 1︎⃣",
  .sequence = {
    0x0031,  // DIGIT ONE
    0xFE0E,  // VARIATION SELECTOR-15
    0x20E3,  // COMBINING ENCLOSING KEYCAP
  },
  .categories  = {
    KEYCAP_BASE,
    VS15,
    COMBINING_ENCLOSING_KEYCAP
  },
  .length = 3,
  .is_emoji = false,
  .has_vs = true
},
{
  .description = "Qualified keycap; Encoded: *️⃣",
  .sequence = {
    0x002A,  // ASTERISK
    0xFE0F,  // VARIATION SELECTOR-16
    0x20E3,  // COMBINING ENCLOSING KEYCAP
  },
  .categories  = {
    KEYCAP_BASE,
    VS16,
    COMBINING_ENCLOSING_KEYCAP
  },
  .length = 3,
  .is_emoji = true,
  .has_vs = true
},
{
  .description = "Lone emoji modifier (Fitzpatrick); Encoded: 🏻",
  .sequence = {
    0x1F3FB, // EMOJI MODIFIER FITZPATRICK TYPE-1-2
  },
  .categories  = {
    EMOJI_MODIFIER
  },
  .length = 1,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Bare modifier base, text default; Encoded: ☝",
  .sequence = {
    0x261D,  // WHITE UP POINTING INDEX
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_TEXT
  },
  .length = 1,
  .is_emoji = false,
  .has_vs = false
},
{
  .description = "Modifier base (text default) + VS-16; Encoded: ☝️",
  .sequence = {
    0x261D,  // WHITE UP POINTING INDEX
    0xFE0F,  // VARIATION SELECTOR-16
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_TEXT,
    VS16
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = true
},
{
  .description = "Modifier base (text default) + skin tone; Encoded: ☝🏻",
  .sequence = {
    0x261D,  // WHITE UP POINTING INDEX
    0x1F3FB, // EMOJI MODIFIER FITZPATRICK TYPE-1-2
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_TEXT,
    EMOJI_MODIFIER
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Modifier base (emoji default) + skin tone; Encoded: 👦🏻",
  .sequence = {
    0x1F466, // BOY
    0x1F3FB, // EMOJI MODIFIER FITZPATRICK TYPE-1-2
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    EMOJI_MODIFIER
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Lone regional indicator; Encoded: 🇺",
  .sequence = {
    0x1F1FA, // REGIONAL INDICATOR SYMBOL LETTER U
  },
  .categories  = {
    REGIONAL_INDICATOR
  },
  .length = 1,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Flag sequence (US); Encoded: 🇺🇸",
  .sequence = {
    0x1F1FA, // REGIONAL INDICATOR SYMBOL LETTER U
    0x1F1F8, // REGIONAL INDICATOR SYMBOL LETTER S
  },
  .categories  = {
    REGIONAL_INDICATOR,
    REGIONAL_INDICATOR
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Text-default emoji + VS-15; Encoded: ☺︎",
  .sequence = {
    0x263A,  // WHITE SMILING FACE
    0xFE0E,  // VARIATION SELECTOR-15
  },
  .categories  = {
    EMOJI_TEXT_PRESENTATION,
    VS15
  },
  .length = 2,
  .is_emoji = false,
  .has_vs = true
},
{
  .description = "Text-default emoji + VS-16; Encoded: ☺️",
  .sequence = {
    0x263A,  // WHITE SMILING FACE
    0xFE0F,  // VARIATION SELECTOR-16
  },
  .categories  = {
    EMOJI_TEXT_PRESENTATION,
    VS16
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = true
},
{
  .description = "Emoji-default emoji + VS-15; Encoded: 😀︎",
  .sequence = {
    0x1F600, // GRINNING FACE
    0xFE0E,  // VARIATION SELECTOR-15
  },
  .categories  = {
    EMOJI_EMOJI_PRESENTATION,
    VS15
  },
  .length = 2,
  .is_emoji = false,
  .has_vs = true
},
{
  .description = "Emoji-default emoji + VS-16; Encoded: 😀️",
  .sequence = {
    0x1F600, // GRINNING FACE
    0xFE0F,  // VARIATION SELECTOR-16
  },
  .categories  = {
    EMOJI_EMOJI_PRESENTATION,
    VS16
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = true
},
{
  .description = "ZWJ family; Encoded: 👨‍👩‍👧",
  .sequence = {
    0x1F468, // MAN
    0x200D,  // ZERO WIDTH JOINER
    0x1F469, // WOMAN
    0x200D,  // ZERO WIDTH JOINER
    0x1F467, // GIRL
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI
  },
  .length = 5,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Long ZWJ family (4 members); Encoded: 👨‍👩‍👧‍👦",
  .sequence = {
    0x1F468, // MAN
    0x200D,  // ZERO WIDTH JOINER
    0x1F469, // WOMAN
    0x200D,  // ZERO WIDTH JOINER
    0x1F467, // GIRL
    0x200D,  // ZERO WIDTH JOINER
    0x1F466, // BOY
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI
  },
  .length = 7,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "ZWJ couple; Encoded: 👨‍❤‍👨",
  .sequence = {
    0x1F468, // MAN
    0x200D,  // ZERO WIDTH JOINER
    0x2764,  // HEAVY BLACK HEART
    0x200D,  // ZERO WIDTH JOINER
    0x1F468, // MAN
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    ZWJ,
    EMOJI_TEXT_PRESENTATION,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI
  },
  .length = 5,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "ZWJ with VS-16 element; Encoded: 👨️‍👩",
  .sequence = {
    0x1F468, // MAN
    0xFE0F,  // VARIATION SELECTOR-16
    0x200D,  // ZERO WIDTH JOINER
    0x1F469, // WOMAN
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    VS16,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI
  },
  .length = 4,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "ZWJ with VS-16 on both elements; Encoded: 👨️‍👩️",
  .sequence = {
    0x1F468, // MAN
    0xFE0F,  // VARIATION SELECTOR-16
    0x200D,  // ZERO WIDTH JOINER
    0x1F469, // WOMAN
    0xFE0F,  // VARIATION SELECTOR-16
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    VS16,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI,
    VS16
  },
  .length = 5,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "ZWJ after modifier sequence; Encoded: 👦🏻‍💻",
  .sequence = {
    0x1F466, // BOY
    0x1F3FB, // EMOJI MODIFIER FITZPATRICK TYPE-1-2
    0x200D,  // ZERO WIDTH JOINER
    0x1F4BB, // PERSONAL COMPUTER
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    EMOJI_MODIFIER,
    ZWJ,
    EMOJI_EMOJI_PRESENTATION
  },
  .length = 4,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "ZWJ technologist with skin tone; Encoded: 👨🏻‍💻",
  .sequence = {
    0x1F468, // MAN
    0x1F3FB, // EMOJI MODIFIER FITZPATRICK TYPE-1-2
    0x200D,  // ZERO WIDTH JOINER
    0x1F4BB, // PERSONAL COMPUTER
  },
  .categories  = {
    EMOJI_MODIFIER_BASE_EMOJI,
    EMOJI_MODIFIER,
    ZWJ,
    EMOJI_EMOJI_PRESENTATION
  },
  .length = 4,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "VS-16 enables ZWJ continuation; Encoded: ☺️‍👩",
  .sequence = {
    0x263A,  // WHITE SMILING FACE
    0xFE0F,  // VARIATION SELECTOR-16
    0x200D,  // ZERO WIDTH JOINER
    0x1F469, // WOMAN
  },
  .categories  = {
    EMOJI_TEXT_PRESENTATION,
    VS16,
    ZWJ,
    EMOJI_MODIFIER_BASE_EMOJI
  },
  .length = 4,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "Tag sequence (England); Encoded: 🏴󠁧󠁢󠁥󠁮󠁧󠁿",
  .sequence = {
    0x1F3F4, // WAVING BLACK FLAG
    0xE0067, // TAG LATIN SMALL LETTER G
    0xE0062, // TAG LATIN SMALL LETTER B
    0xE0065, // TAG LATIN SMALL LETTER E
    0xE006E, // TAG LATIN SMALL LETTER N
    0xE0067, // TAG LATIN SMALL LETTER G
    0xE007F, // CANCEL TAG
  },
  .categories  = {
    TAG_BASE,
    TAG_SEQUENCE,
    TAG_SEQUENCE,
    TAG_SEQUENCE,
    TAG_SEQUENCE,
    TAG_SEQUENCE,
    TAG_TERM
  },
  .length = 7,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "TAG_BASE as ZWJ element; Encoded: 🏴‍😀",
  .sequence = {
    0x1F3F4, // WAVING BLACK FLAG
    0x200D,  // ZERO WIDTH JOINER
    0x1F600, // GRINNING FACE
  },
  .categories  = {
    TAG_BASE,
    ZWJ,
    EMOJI_EMOJI_PRESENTATION
  },
  .length = 3,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "TAG_BASE + VS-16 + ZWJ; Encoded: 🏴️‍😀",
  .sequence = {
    0x1F3F4, // WAVING BLACK FLAG
    0xFE0F,  // VARIATION SELECTOR-16
    0x200D,  // ZERO WIDTH JOINER
    0x1F600, // GRINNING FACE
  },
  .categories  = {
    TAG_BASE,
    VS16,
    ZWJ,
    EMOJI_EMOJI_PRESENTATION
  },
  .length = 4,
  .is_emoji = true,
  .has_vs = false
},
{
  .description = "TAG_BASE + VS-15; Encoded: 🏴︎",
  .sequence = {
    0x1F3F4, // WAVING BLACK FLAG
    0xFE0E,  // VARIATION SELECTOR-15
  },
  .categories  = {
    TAG_BASE,
    VS15
  },
  .length = 2,
  .is_emoji = false,
  .has_vs = true
},
{
  .description = "TAG_BASE + VS-16; Encoded: 🏴️",
  .sequence = {
    0x1F3F4, // WAVING BLACK FLAG
    0xFE0F,  // VARIATION SELECTOR-16
  },
  .categories  = {
    TAG_BASE,
    VS16
  },
  .length = 2,
  .is_emoji = true,
  .has_vs = true
},
