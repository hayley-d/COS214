# Compiler and flags
CC = g++
CFLAGS = -fprofile-arcs -ftest-coverage -O0 -g
LDFLAGS = -fprofile-arcs -ftest-coverage

# Directories
SRC_DIR = .
OBJ_DIR = obj
COV_DIR = coverage

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Executable name
EXEC = my_program

# Targets
.PHONY: all clean coverage

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC) *.gcda *.gcno *.gcov $(COV_DIR)

coverage: all
	@mkdir -p $(COV_DIR)
	./$(EXEC)
	gcov -o $(OBJ_DIR) main.cpp
	mv main.cpp.gcov $(COV_DIR)
