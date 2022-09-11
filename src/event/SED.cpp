#include "SED.h"


SED::SED(){

}

SED::~SED(){

}

void SED::add(Event& event){
    _eventSet.insert(&event);
}

void SED::run(){
    while(_eventSet.size() != 0){
        Event* event = *_eventSet.begin();
        _eventSet.erase(_eventSet.begin());
        event->execute();
        delete event;
    }
}

bool EventComparator::operator()(const Event* event1, const Event* event2) const
{
    return (event1->hour() > event2->hour());
}
