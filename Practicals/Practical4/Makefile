# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -O2 -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov

# Directories and files
SRCDIR = .
OBJDIR = obj
BINDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC = $(BINDIR)/main

# Valgrind tool for memory checking
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Create necessary directories
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Compile all the .cpp files to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the objects and create the executable
$(EXEC): $(OBJECTS) | $(BINDIR)
	$(CXX) $(OBJECTS) -o $(EXEC) $(LDFLAGS)

# Default target: compile and link
.PHONY: all
all: $(EXEC)

# Run the program
.PHONY: run
run: $(EXEC)
	./$(EXEC)

# Memory check using Valgrind
.PHONY: memcheck
memcheck: $(EXEC)
	$(VALGRIND) ./$(EXEC)

# Code coverage
.PHONY: coverage
coverage: $(EXEC)
	./$(EXEC)
	gcov $(SOURCES)

# Clean up the compiled objects, binary, and gcov coverage files
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR) *.gcda *.gcno *.gcov

