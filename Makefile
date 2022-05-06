CXX = g++ -std=c++17 -c
CXX_FLAGS = -lgtest -lgtest_main -lpthread 
BUILD_OUTPUT = g++ -o
OBJ = ./*.o
HEADER = ./include/*.hpp
SRC = src/*.cpp
EXE = ./build/exe
HELPER_FILES = src/o* src/e* src/p* src/u* src/s*
TEST_FILES = tests/*
DIR = ./build
TEST_DIR = ./build/test
MKDIR = mkdir
TARGET = schm 
TARGET_TEST = build/test/test_out
RM = rm -rf

.PHONY: all build test exe run clean

all: build exe schm 

build:
	$(MKDIR) $(DIR)

test:
	$(MKDIR) $(DIR)
	$(MKDIR) $(TEST_DIR)
	$(CXX) $(HELPER_FILES)
	$(CXX) $(TEST_FILES)
	$(BUILD_OUTPUT) $(TARGET_TEST) $(OBJ) $(CXX_FLAGS)
	./$(TARGET_TEST)

exe:
	$(MKDIR) $(EXE)

schm: $(OBJ)
	$(BUILD_OUTPUT) $(EXE)/$(TARGET) $(OBJ)

./*.o: $(HEADER)

$(OBJ): $(SRC)
	$(CXX) $(SRC)

clean:
	$(RM) $(DIR)
	$(RM) *.o
	$(RM) $(TARGET_TEST)