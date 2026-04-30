
all: emoji_presentation_scanner.c

%.c: %.rl Makefile
	ragel -F1 $<

CFLAGS= \
	-O2 \
	-Demoji_text_iter_t="char *" \
	-DEMOJI_LINKAGE= \
	$(NULL)

%.o: %.c Makefile
	$(CC) -c -o $@ $< $(CFLAGS)

emoji_test_data.h: emoji_test_data.py
	python3 $< > $@

emoji_test: emoji_test.c emoji_test_data.h emoji_presentation_scanner.c
	$(CC) -o $@ $<

.PHONY: test
test: emoji_test
	./emoji_test

size: emoji_presentation_scanner.o
	size $<

clean:
	rm -f emoji_presentation_scanner.o emoji_test
