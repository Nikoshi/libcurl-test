CC=gcc
CFLAGS=-O2
CLIBS= $(shell curl-config --libs)
SRC=main.c
OUT=curl-test
SIMPLE_SRC=simple.c
SIMPLE_OUT=simple-curl-test

all: $(OUT) $(SIMPLE_OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(CLIBS) $(SRC) -o $(OUT)
	strip $(OUT)

$(SIMPLE_OUT): $(SIMPLE_SRC)
	$(CC) $(CFLAGS) $(CLIBS) $(SIMPLE_SRC) -o $(SIMPLE_OUT)
	strip $(SIMPLE_OUT)

clean:
	rm -f $(OUT) $(SIMPLE_OUT)

.PHONY: clean all
