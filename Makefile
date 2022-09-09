# ==== DOXYGEN ====
doc:
	doxygen Doxyfile
	ln -s -f "$(PWD)/doc/html/index.html" "$(PWD)/doc"
# Always recompile doc
.PHONY: doc

# ==== COMPILATION ====
CC = g++
CFLAGS = -Wall
EXEC_NAME = main
INCLUDES = $(wildcard src/*.h)
LIBS =
OBJ_FILES = Bank.o Cashier.o Client.o ClientArrival.o ClientDeparture.o Event.o \
	PoissonRandomGenerator.o RandomGenerator.o SED.o WaitingLine.o
INSTALL_DIR = ./bin

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(OBJ_FILES): $(INCLUDES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) src/main.cpp

%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< 

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)


# SRC_DIR = src
# BUILD_DIR = build

# OBJ = Bank.o Cashier.o Client.o ClientArrival.o ClientDeparture.o Event.o PoissonRandomGenerator.o SED.o WaitingLine.o

# HEADERS = $(wildcard $(SRC_DIR)/*.h)

# $(OBJ): $(HEADERS)

# $(BUILD_DIR)/%.cpp.o: %.cpp
# 	mkdir $(dir $@)
# 	g++ -c $< -o $@

# main: $(OBJ)
# 	g++ -o bin/main $(OBJ)

# info:
# 	@echo "[*] Headers dir:      ${HEADERS}     "
# 	@echo "[*] Objects:         ${OBJ}     "