CFLAGS = -ggdb3 -O2 -std=gnu99 -Wall -pedantic -Isrc -D__BUILD_HASHMAP

all: clean test_main

test_main: \
    test/main.c \
    src/hashmap-link-hash.c

clean:
	rm -f ./hmtest
	rm -f ./core.*
