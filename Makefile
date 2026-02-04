CC = gcc

CFLAGS = -Wall

TARGET = main

SRCS = main.c modulofunc.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
