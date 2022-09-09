#include "SED.h"


SED::SED(){

}

SED::~SED(){

}

void SED::add(Event& event){
    _eventSet.insert(&event);
}


bool EventComparator::operator()(const Event& event1, const Event& event2)
{
    return (event1.hour() > event2.hour());
}
