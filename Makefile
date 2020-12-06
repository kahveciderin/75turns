CC = g++

CFLAGS  = -Wall -lncurses

TARGET = main

all: clean $(TARGET).cpp

	$(CC) $(TARGET).cpp -o $(TARGET) -lncurses $(CFLAGS)

clean:
	$(RM) $(TARGET)

run: all
	./$(TARGET)
	make clean