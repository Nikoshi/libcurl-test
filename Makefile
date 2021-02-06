CC=gcc
CFLAGS=-O2 $(curl-config --libs)
SRC=main.c
OUT=curl-test

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	strip $(OUT)

clean:
	rm -f $(OUT)

.PHONY: clean
