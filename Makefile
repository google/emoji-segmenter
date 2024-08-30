emoji-presentation-scanner: emoji_presentation_scanner.c emoji_presentation_scanner_vs.c

emoji_presentation_scanner.c: emoji_presentation_scanner.rl Makefile
	ragel $<

emoji_presentation_scanner_vs.c: emoji_presentation_scanner_vs.rl Makefile
	ragel $<