#if !defined(__CLIENTDEPARTURE_H__)
#define __CLIENTDEPARTURE_H__

#include "Event.h"

class ClientDeparture : public Event {

    private:

    public:

    ClientDeparture();

    ~ClientDeparture();

    void execute();

};

#endif // __CLIENTDEPARTURE_H__
