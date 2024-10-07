# Define the compiler
CC = gcc

# Define the flags for the compiler
CFLAGS = -Wall -g

# Define the target executable
TARGET = timer

# Define the build rule for the executable
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# Define the rule to clean up generated files
clean:
	rm -f $(TARGET)