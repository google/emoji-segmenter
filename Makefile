all: \
	emoji_presentation_scanner.o \
	emoji_presentation_scanner_vs.o \
	$(NULL)
	size $^

%.c: %.rl Makefile
	ragel -F1 $<

CFLAGS= \
	-O2 \
	-Demoji_text_iter_t="char *" \
	-DEMOJI_LINKAGE= \
	$(NULL)

%.o: %.c Makefile
	$(CC) -c -o $@ $< $(CFLAGS)