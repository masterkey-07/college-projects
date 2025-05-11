CC = gcc

# FLAGS
LDFLAGS = -lcriterion
CFLAGS = -Wall -I. -Iinclude

# FOLDERS
SRC_DIR=src
TESTS_DIR=tests
DIST_DIR=dist

# FILES
TARGET = $(DIST_DIR)/main
TEST = $(wildcard tests/*.c)
SRC = $(wildcard $(SRC_DIR)/*.c) 
SRC_OBJS = $(SRC:$(SRC_DIR)/%.c=$(DIST_DIR)/%.o)

# TESTOBJ = $(TEST:.c=.o)

all: $(DIST_DIR) $(TARGET) 

$(DIST_DIR):
	mkdir $(DIST_DIR)

$(TARGET): $(SRC_OBJS) 
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_OBJS)

$(DIST_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) input/lexemas.txt

clean:
	rm -f $(TARGET) $(DIST_DIR)

.PHONY: all clean
