CC = gcc

CFLAGS = -std=c99 -Wall -Wextra
OBJS = $(SRC_FILES:.c=.o)

TARGET = rake

SRC_FILES = src/main.c src/cmds.c

all: $(TARGET)


$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)

clean:
	rm -f $(TARGET)
