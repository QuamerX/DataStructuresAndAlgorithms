# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
DEPFLAGS = -MMD -MP  # Flags for dependency generation

# Find all .c files recursively and set them as source files
SRCS = $(shell find . -name "*.c")
BUILD_DIR = Build
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# Target executable
TARGET = $(BUILD_DIR)/DSA

# Rule to build the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lm

# Pattern rule for building .o files from .c files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# Include dependency files for .o files
-include $(DEPS)

# Clean rule to delete built files and dependencies
clean:
	@rm -rf $(BUILD_DIR)
