CC = g++
CFLAGS = -std=c++11

SRC_DIR = src
BUILD_DIR = build
EXECUTABLE_FILE = a.out

OBJECTS = $(BUILD_DIR)/main.o


.PHONY: all build_objects make_build_dir clean

all: make_build_dir build_objects

build_objects: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

make_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) *.o *.out


mainSensitivityList = $(SRC_DIR)/main.cpp

$(BUILD_DIR)/main.o: $(mainSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o