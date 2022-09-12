#include "ClientDeparture.h"

ClientDeparture::ClientDeparture( Bank& bank, double hour, Client& client, Cashier& cashier) : Event(bank, hour), _bank(&bank)
{
    _client = &client;
    _cashier = &cashier;
}

ClientDeparture::~ClientDeparture()
{}

void ClientDeparture::execute()
{
    // remove client
    // update realLength
    cout << "departure" << endl;
    _bank->setRealLength(hour());
    delete _client;
    // manage Cashier depending presence of other clients
    if(_bank->nbClients() == 0){
        _cashier->wait();
    }
    else{
        Client* newClient = _bank->getWaitingClient();
        _cashier->serve(newClient);
    }
}
