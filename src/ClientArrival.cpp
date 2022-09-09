#include "ClientArrival.h"

#include <random>


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
    double hpa = bank->computeNextArrivalTime();
    // create the new Arrival
    ClientArrival* newArrival = new ClientArrival(*bank, hour() + hpa);
    // add it to the simulation
    bank->add(*newArrival);
}