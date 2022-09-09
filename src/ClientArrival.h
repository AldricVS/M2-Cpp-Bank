#if !defined(__ARRIVALEVENT_H__)
#define __ARRIVALEVENT_H__

#include "Bank.h"
#include "Event.h"

class ClientArrival : public Event
{
private:
    Bank* bank;

public:

    ClientArrival(Bank& bank, double hour);
    ~ClientArrival();

    /**
     * @brief Create a cashier and manage it in the bank depending if a Cashier is free
     * @return (void)
     */
    void execute();

};

#endif // __ARRIVALEVENT_H__
