# Define variables
CC = gcc
CFLAGS = -I./include
SRC = main.c src/selectionSortArray.c src/insertionSortArray.c utils/utilis.c 
OBJ = $(SRC:.c=.o)
TARGET = sorting

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
