# # Run doxygen on the src file and create a symlink of the 
# # "index.html" in the "doc" directory
# doc:
# 	doxygen Doxyfile
# 	ln -s "$(PWD)/doc/html/index.html" "$(PWD)/doc"

# SRC_DIR = src
# BANK_DIR = $(SRC_DIR)/bank
# EVENT_DIR = $(SRC_DIR)/event

# VPATH = $(SRC_DIR)
# BUILD_DIR = build

# BANK_OBJ = Bank.o Cashier.o Client.o WaitingList.o
# EVENT_OBJ = ClientArrival.o ClientDeparture.o Event.h SED.h

# Bank.o: $(BANK_DIR)/Bank.h $(BANK_DIR)/Cashier.h $(BANK_DIR)/WaitingList.h src/event/SED.h
# Cashier.o: $(BANK_DIR)/Cashier.h $(BANK_DIR)/Client.h $(BANK_DIR)/Bank.h
# Client.o: $(BANK_DIR)/Client.h $(BANK_DIR)/Client.cpp
# WaitingList.o: $(BANK_DIR)/WaitingList.h $(BANK_DIR)/Client.h $(BANK_DIR)/Bank.h

# SED.o: $(EVENT_DIR)/SED.h $(EVENT_DIR)/Event.h
# Event.o: $(EVENT_DIR)/Event.h $(EVENT_DIR)/SED.h
# ClientArrival: $(BANK_DIR)/Bank.h $(BANK_DIR)/Cashier.h $(BANK_DIR)/Client.h $(EVENT_DIR)/Event.h $(EVENT_DIR)/SED.h
# ClientDeparture: $(BANK_DIR)/Bank.h $(EVENT_DIR)/Event.h $(EVENT_DIR)/SED.h

# tLaunch: $(BANK_OBJ) test/tLaunch.cpp
# 	g++ -o tLaunch $(BANK_OBJ) test/tLaunch.cpp


# clean :
# 	rm ./src/*.o


TARGET = tLaunch

CC = gcc
CFLAGS = -g

OUTDIR = ./bin
SUBDIR = bank event
DIR_OBJ = ./obj

INCS = $(wildcard *.h $(foreach fd, $(SUBDIR), $(fd)/*.h))
SRCS = $(wildcard *.c $(foreach fd, $(SUBDIR), $(fd)/*.c))
NODIR_SRC = $(notdir $(SRCS))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o)) # obj/xxx.o obj/folder/xxx .o
INC_DIRS = -I./ $(addprefix -I, $(SUBDIR))

PHONY := $(TARGET)
$(TARGET): $(OBJS)
    $(CC) -o $(OUTDIR)/$@ $(OBJS)

$(DIR_OBJ)/%.o: %.c $(INCS)
    mkdir -p $(@D)
    $(CC) -o $@ $(CFLAGS) -c $< $(INC_DIRS)

PHONY += clean
clean:
    rm -rf $(OUTDIR)/* $(DIR_OBJ)/*

PHONY += echoes
echoes:
    @echo "INC files: $(INCS)"
    @echo "SRC files: $(SRCS)"
    @echo "OBJ files: $(OBJS)"
    @echo "LIB files: $(LIBS)"
    @echo "INC DIR: $(INC_DIRS)"
    @echo "LIB DIR: $(LIB_DIRS)"

.PHONY = $(PHONY)
