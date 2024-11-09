# Compiler and flags
CC = gcc
CFLAGS = -fopenmp -Wall -Wextra -I./src -I./tests

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Executable name
MAIN_EXEC = $(BUILD_DIR)/main
TEST_EXEC = $(BUILD_DIR)/integral

# Source files
SRC_FILES = $(SRC_DIR)/integral.c
MAIN_FILE = $(SRC_DIR)/main.c
TEST_FILES = $(TEST_DIR)/test_integral.c $(SRC_FILES)

# Default target: Build both main and tests
all: main test

# Build the main executable
main: $(MAIN_EXEC)

$(MAIN_EXEC): $(MAIN_FILE) $(SRC_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(MAIN_FILE) $(SRC_FILES) -o $(MAIN_EXEC)

run: $(MAIN_EXEC)
	$(MAIN_EXEC) 100000000000

# Build and run tests with Criterion
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Compile test files
$(TEST_EXEC): $(SRC_FILES) $(TEST_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(TEST_FILES) -o $(TEST_EXEC) -lcriterion

# Clean up
clean:
	rm -rf $(BUILD_DIR)

# $(TEST_EXEC): $(TEST_FILES)
# 	@mkdir -p $(BUILD_DIR)
# 	$(CC) $(CFLAGS) $(TEST_FILES) -o $(TEST_EXEC) -lcriterion