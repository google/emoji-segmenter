emoji-presentation-scanner: emoji_presentation_scanner.c emoji_presentation_scanner_vs.c

emoji_presentation_scanner.c: emoji_presentation_scanner.rl Makefile
	ragel -F1 $<

emoji_presentation_scanner_vs.c: emoji_presentation_scanner_vs.rl Makefile
	ragel -F1 $<