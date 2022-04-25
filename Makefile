CXX = g++ -std=c++17 -c
BUILD_OUTPUT = g++ -o
OBJ = ./*.o
SRC = src/*.cpp
BUILD = ./build/objects
EXE = ./build/exe
TARGET = schm 
RM = rm -f

.PHONY: all run clean

all: schm 

run: 
	$(EXE)/$(TARGET)

schm: $(OBJ)
	$(BUILD_OUTPUT) $(EXE)/$(TARGET) $(OBJ)

./*.o: ./include/*.hpp

$(OBJ): $(SRC)
	$(CXX) $(SRC)

clean:
	$(RM) $(EXE)/* 
	$(RM) *.o
