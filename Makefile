CC=		gcc
CFLAGS=		-ansi -pedantic -g -Wall -Wextra -D_DEFAULT_SOURCE

SRC=		db.c \
		staq.c
BIN=		staq

all: $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)
