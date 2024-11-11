# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
DEPFLAGS = -MMD -MP  # Flags for dependency generation

# Find all .c files recursively and set them as source files
SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = DSA

# Rule to build the executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Pattern rule for building .o files from .c files
%.o: %.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# Include dependency files for .o files
-include $(OBJS:.o=.d)

# Clean rule to delete built files and dependencies
clean:
	@rm -f $(OBJS) $(TARGET) $(OBJS:.o=.d)

