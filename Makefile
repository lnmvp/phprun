CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/phprun.c src/lexer.c
OBJ = $(SRC:.c=.o)
TARGET = phprun

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) $(OBJ)
