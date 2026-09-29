# lockbox
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
BIN = lockbox

all: $(BIN)

$(BIN): main.c env.c
	$(CC) $(CFLAGS) -o $(BIN) main.c env.c

clean:
	rm -f $(BIN)
