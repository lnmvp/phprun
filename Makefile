CC = gcc
CFLAGS = -Wall -g
SRC = src/phprun.c src/lexer.c src/parser.c
OBJ = $(SRC:.c=.o)
TARGET = phprun

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
