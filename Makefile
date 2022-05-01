CXX = g++ -std=c++17 -c
BUILD_OUTPUT = g++ -o
OBJ = ./*.o
SRC = src/*.cpp
EXE = ./build/exe
DIR = ./build
MKDIR = mkdir
TARGET = schm 
RM = rm -rf

.PHONY: all build exe run clean

all: build exe schm 

build:
	$(MKDIR) $(DIR)

exe:
	$(MKDIR) $(EXE)

schm: $(OBJ)
	$(BUILD_OUTPUT) $(EXE)/$(TARGET) $(OBJ)

./*.o: ./include/*.hpp

$(OBJ): $(SRC)
	$(CXX) $(SRC)

clean:
	$(RM) $(DIR)
	$(RM) *.o
