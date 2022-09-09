#if !defined(__CLIENTDEPARTURE_H__)
#define __CLIENTDEPARTURE_H__

#include "../bank/Bank.h"
#include "../bank/Client.h"
#include "../bank/Cashier.h"
#include "Event.h"

class ClientDeparture : public Event
{
private:
    
    Bank* _bank;
    Client* _client;
    Cashier* _cashier;

public:

    ClientDeparture(double hour, Bank* bank, Client* client, Cashier* cashier);

    ~ClientDeparture();

    void execute();

};

#endif // __CLIENTDEPARTURE_H__
