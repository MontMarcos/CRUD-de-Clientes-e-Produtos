CC = gcc
CFLAGS = -Wall

TARGET = main
TARGET_GUI = main_gui

SRCS = main.c modulofunc.c
SRCS_GUI = interface.c modulofunc.c

GTK_FLAGS = $(shell pkg-config --cflags --libs gtk+-3.0)

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

gui:
	$(CC) $(CFLAGS) $(SRCS_GUI) $(GTK_FLAGS) -o $(TARGET_GUI)

clean:
	rm -f $(TARGET) $(TARGET_GUI)

.PHONY: all make_gui clean
