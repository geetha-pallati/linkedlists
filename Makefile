# 1. Variables: Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# 2. Target: The name of your final executable
TARGET = dll_program

# 3. Build Rule: How to create the executable
all: $(TARGET)

$(TARGET): doublylinkedlist.o
	$(CC) $(CFLAGS) -o $(TARGET) doublylinkedlist.o

# 4. Object Rule: How to create the .o file from .c
doublylinkedlist.o: doublylinkedlist.c
	$(CC) $(CFLAGS) -c doublylinkedlist.c

# 5. Clean Rule: Remove the compiled files to start fresh
clean:
	rm -f $(TARGET) *.o