#include "ClientArrival.h"


ClientArrival::ClientArrival(Bank& bank, double hour) : Event(bank, hour)
{
    
}

ClientArrival::~ClientArrival()
{
    
}

void ClientArrival::execute()
{
    Client* client = new Client(hour());
    Cashier* firstFreeCashier = bank->firstFree();
    // manage client depending if a cashier is free or not
    if(firstFreeCashier == nullptr){
        firstFreeCashier->serve(client);
    }
    else{
        bank->addToLine(client);
    }
    // calculation of the arrival of the next client
    double hpa = 10.0; // TODO use fish law
    // create the new Arrival
    ClientArrival newArrival(*bank, hpa);
    // add it to the simulation
    bank->add(newArrival);

}
