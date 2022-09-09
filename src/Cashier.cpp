#include "Cashier.h"
#include "ClientDeparture.h"

Cashier::Cashier(Bank& bank, double averageServiceTime): _randomGenerator(averageServiceTime)
{
    _bank = &bank;
    _averageServiceTime = averageServiceTime;
    _client = nullptr;
    _nbClientsServed = 0;
    _workingTime = 0;
    
}

Cashier::~Cashier()
{}

double Cashier::averageServiceTime() const
{
    return _averageServiceTime;
}

int Cashier::nbClients() const
{
    return _nbClientsServed;
}

double Cashier::OccupationRate()
{
    return _workingTime/_bank->realLength();
}

bool Cashier::isFree()
{
    return _client==nullptr;
}

void Cashier::serve(Client* client)
{
    _client = client;
    double servingTime = _randomGenerator.nextDouble();
    ClientDeparture* newEvent = new ClientDeparture(*_bank, client->arrivalTime() + servingTime, *_client, *this); 
    _workingTime +=servingTime;
    _bank->add(*newEvent);

}

void Cashier::wait()
{

}
