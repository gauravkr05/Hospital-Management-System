# ===== Makefile =====

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Output binary
TARGET = $(BINDIR)/hospital_mgmt

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Create necessary directories if not present
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file into .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean

