# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
LDFLAGS = -lgcov --coverage
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC = main

# Target: Build and link all files
all: $(EXEC)

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files into the final executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Run the executable
run: all
	./$(EXEC)

# Clean up object files, executable, and coverage data
clean:
	rm -f $(OBJS) $(EXEC) *.gcda *.gcno *.gcov

# Run memory checks using Valgrind
memcheck: all
	valgrind --leak-check=full ./$(EXEC)

# Generate code coverage report
coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: clean all
	./$(EXEC)
	# Generate coverage report
	gcov $(SRCS)

.PHONY: all run clean memcheck coverage

