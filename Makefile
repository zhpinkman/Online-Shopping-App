CC = g++
CFLAGS = -std=c++11

SRC_DIR = src
BUILD_DIR = build
EXECUTABLE_FILE = a.out

OBJECTS = $(BUILD_DIR)/main.o \
		  $(BUILD_DIR)/Interface.o \
		  $(BUILD_DIR)/Tools.o


.PHONY: all build_objects make_build_dir clean

all: make_build_dir build_objects

build_objects: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE_FILE)

make_build_dir:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) *.o *.out


mainHeaderSensitivities = $(InterfaceHeaderSensitivities)

InterfaceHeaderSensitivities = $(SRC_DIR)/Interface.hpp \
							   $(SRC_DIR)/Exception.hpp \
							   $(SRC_DIR)/Exceptions.hpp \
							   $(SRC_DIR)/constants.hpp \
							   $(ToolsHeaderSensitivities)

ToolsHeaderSensitivities = $(SRC_DIR)/Tools.hpp


mainSensitivityList = $(SRC_DIR)/main.cpp \
					  $(mainHeaderSensitivities)

InterfaceSensitivityList = $(SRC_DIR)/Interface.cpp \
						   $(InterfaceHeaderSensitivities) \

ToolsSensitivityList = $(SRC_DIR)/Tools.cpp \
					   $(ToolsHeaderSensitivities)



$(BUILD_DIR)/main.o: $(mainSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Interface.o: $(InterfaceSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Interface.cpp -o $(BUILD_DIR)/Interface.o

$(BUILD_DIR)/Tools.o: $(ToolsSensitivityList)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Tools.cpp -o $(BUILD_DIR)/Tools.o