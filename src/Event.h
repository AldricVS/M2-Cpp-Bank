#if !defined(__EVENT_H__)
#define __EVENT_H__

#include "SED.h"

class Event
{
private:
    SED* _sed;
    double _hour;

public:

    Event(SED& sed);

    ~Event();

    virtual void execute();

    double hour();

};

#endif // __EVENT_H__
