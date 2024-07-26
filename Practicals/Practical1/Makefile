# Variables
CXX = g++
CXXFLAGS = -Wall -g
TARGET = myProgram

# Source files
SRCS = main.cpp Menu.cpp MenuItem.cpp Course.cpp Dessert.cpp MainCourse.cpp Starter.cpp

# Header files
HEADERS = Menu.h MenuItem.h Course.h Dessert.h MainCourse.h Starter.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: clean
