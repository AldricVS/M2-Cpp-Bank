#ifndef __CLIENTARRIVAL_H__
#define __CLIENTARRIVAL_H__

#include "../bank/Bank.h"
#include "Event.h"

class ClientArrival : public Event
{
private:
    Bank* _bank;

public:

    ClientArrival(Bank& bank, double hour);
    ~ClientArrival();

    /**
     * @brief Create a cashier and manage it in the bank depending if a Cashier is free
     * @return (void)
     */
    void execute();

};


#endif // __CLIENTARRIVAL_H__