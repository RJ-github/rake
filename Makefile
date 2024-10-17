CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Iheaders
OBJS = $(SRC_FILES:.c=.o)

TARGET = rake

SRC_FILES = src/main.c src/rake_new.c src/rake_build.c

all: $(TARGET)


$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o bin/$(TARGET)

clean:
	rm -f bin/$(TARGET)
