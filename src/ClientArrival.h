#if !defined(__ARRIVALEVENT_H__)
#define __ARRIVALEVENT_H__

#include "Event.h"

class ClientArrival : public Event{

    private:

    public:

    ClientArrival();

    ~ClientArrival();

    void execute();

};

#endif // __ARRIVALEVENT_H__
