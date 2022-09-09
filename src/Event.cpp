#include "Event.h"

Event::Event(SED& sed, double hour){
    _sed = &sed;
    _hour = hour;
}

double Event::hour(){
    return _hour;
}

