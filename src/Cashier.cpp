#include "Cashier.h"
#include "ClientDeparture.h"

Cashier::Cashier(Bank& bank, double averageServiceTime)
{
    _bank = &bank;
    _averageServiceTime = averageServiceTime;
    _client = nullptr;
    _nbClientsServed = 0;
    _workingTime = 0;
}

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
    ClientDeparture* newEvent = new ClientDeparture(*_bank, _averageServiceTime, *_client, *this); // todo change averageserviceTime
    _workingTime +=_averageServiceTime;
    _bank->add(*newEvent);

}

void Cashier::wait()
{

}
