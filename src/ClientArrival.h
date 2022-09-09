#if !defined(__ARRIVALEVENT_H__)
#define __ARRIVALEVENT_H__

#include "Bank.h"
#include "Event.h"

class ClientArrival : public Event
{
private:
    Bank* bank;

public:

    ClientArrival(double hour, Bank& bank);
    ~ClientArrival();

    void execute();

};

#endif // __ARRIVALEVENT_H__
