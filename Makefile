CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/Node.c $(SRC_DIR)/SparseMatrix.c main.c

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Executable
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) main