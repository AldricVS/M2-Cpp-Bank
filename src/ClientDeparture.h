#if !defined(__CLIENTDEPARTURE_H__)
#define __CLIENTDEPARTURE_H__

#include "Bank.h"
#include "Client.h"
#include "Cashier.h"
#include "Event.h"

class ClientDeparture : public Event
{
private:
    
    Bank* _bank;
    Client* _client;
    Cashier* _cashier;

public:

    ClientDeparture(Bank& bank, double hour, Client& client, Cashier& cashier);

    ~ClientDeparture();

    void execute();

};

#endif // __CLIENTDEPARTURE_H__
