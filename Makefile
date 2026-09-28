# lockbox
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
BIN = lockbox

all: $(BIN)

$(BIN): main.c
	$(CC) $(CFLAGS) -o $(BIN) main.c

clean:
	rm -f $(BIN)
