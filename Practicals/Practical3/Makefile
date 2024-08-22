# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g
LDFLAGS = --coverage
LDLIBS = -lgcov

# Source files
SRCS = Infantry.cpp Cavalry.cpp Artillery.cpp Legion.cpp Ambush.cpp Flanking.cpp Fortification.cpp TacticalCommand.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Headers
HEADERS = UnitComponent.h Infantry.h Cavalry.h Artillery.h CompositeUnit.h Legion.h Direction.h Cohort.h Century.h Ambush.h BattleStrategy.h Flanking.h Fortification.h TacticalCommand.h

# Executable name
TARGET = roman_battle_simulator

# Valgrind settings
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Default rule: compile the program
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Compile each .cpp file into .o file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Check for memory leaks with Valgrind
memcheck: $(TARGET)
	$(VALGRIND) ./$(TARGET)

# Run code coverage
coverage: $(TARGET)
	./$(TARGET)
	gcov $(SRCS)

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS) *.gcno *.gcda *.gcov

.PHONY: all run memcheck coverage clean
