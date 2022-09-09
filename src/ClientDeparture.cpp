#include "ClientDeparture.h"

ClientDeparture::ClientDeparture( Bank& bank, double hour, Client& client, Cashier& cashier) : Event(bank, hour)
{
    _client = &client;
    _cashier = &cashier;
}

ClientDeparture::~ClientDeparture()
{
    
}

void ClientDeparture::execute()
{
    
}
