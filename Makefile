# Run doxygen on the src file and create a symlink of the 
# "index.html" in the "doc" directory
doc:
	doxygen Doxyfile
	ln -s -f "$(PWD)/doc/html/index.html" "$(PWD)/doc"
# Always regenerate the documentation
.PHONY: doc


SRC_DIR = src
BANK_DIR = $(SRC_DIR)/bank
EVENT_DIR = $(SRC_DIR)/event

VPATH = $(SRC_DIR)
BUILD_DIR = build

BANK_OBJ = Bank.o Cashier.o Client.o WaitingList.o
EVENT_OBJ = ClientArrival.o ClientDeparture.o Event.h SED.h

Bank.o: $(BANK_DIR)/Bank.h $(BANK_DIR)/Cashier.h $(BANK_DIR)/WaitingList.h src/event/SED.h
Cashier.o: $(BANK_DIR)/Cashier.h $(BANK_DIR)/Client.h $(BANK_DIR)/Bank.h
Client.o: $(BANK_DIR)/Client.h $(BANK_DIR)/Client.cpp
WaitingList.o: $(BANK_DIR)/WaitingList.h $(BANK_DIR)/Client.h $(BANK_DIR)/Bank.h

SED.o: $(EVENT_DIR)/SED.h $(EVENT_DIR)/Event.h
Event.o: $(EVENT_DIR)/Event.h $(EVENT_DIR)/SED.h
ClientArrival: $(BANK_DIR)/Bank.h $(BANK_DIR)/Cashier.h $(BANK_DIR)/Client.h $(EVENT_DIR)/Event.h $(EVENT_DIR)/SED.h
ClientDeparture: $(BANK_DIR)/Bank.h $(EVENT_DIR)/Event.h $(EVENT_DIR)/SED.h

tLaunch: $(BANK_OBJ) test/tLaunch.cpp
	g++ -o tLaunch $(BANK_OBJ) test/tLaunch.cpp


clean :
	rm ./src/*.o
