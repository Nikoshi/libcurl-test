CC=gcc
CFLAGS=-O2
CLIBS= $(shell curl-config --libs)
SRC=main.c
OUT=curl-test

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(CLIBS) $(SRC) -o $(OUT)
	strip $(OUT)

clean:
	rm -f $(OUT)

.PHONY: clean
