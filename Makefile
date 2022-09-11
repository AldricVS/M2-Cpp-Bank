
BIN_DIR ?= bin
BUILD_DIR ?= build
SRC_DIRS ?= src

MAINS := build/src/main.cpp.o build/src/test/testBank.cpp.o build/src/test/testInput.cpp.o

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

main: create_folders $(OBJS)
	g++ $(filter-out $(MAINS), $(OBJS)) $(BUILD_DIR)/src/main.cpp.o -o $(BIN_DIR)/main $(LDFLAGS)

testBank: create_folders $(OBJS)
	g++ $(filter-out $(MAINS), $(OBJS)) $(BUILD_DIR)/src/test/testBank.cpp.o -o $(BIN_DIR)/testBank $(LDFLAGS)

testInput: create_folders $(OBJS)
	g++ $(filter-out $(MAINS), $(OBJS)) $(BUILD_DIR)/src/test/testInput.cpp.o -o $(BIN_DIR)/testInput $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	g++ $(CPPFLAGS) -c $< -o $@

create_folders:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BUILD_DIR)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
