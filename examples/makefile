# Makefile for hello.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable
TARGET = hello.exe

# Default target: build
all: $(TARGET)

# Build target
$(TARGET): hello.c
	$(CC) $(CFLAGS) -o $(TARGET) hello.c

# Run target
run: $(TARGET)
	./$(TARGET)

# Clean target
clean:
	rm $(TARGET)
