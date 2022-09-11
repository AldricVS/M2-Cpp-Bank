#include "SED.h"
#include <iostream>
using namespace std;

SED::SED(){
    _hour = 0;
}

SED::~SED(){

}

void SED::add(Event& event){
    _eventSet.insert(&event);
}

double SED::hour(){
    return _hour;
}

void SED::run(){
    cout << "test" << endl; 

    while(_eventSet.size() != 0){
        Event* event = *_eventSet.begin();
        _eventSet.erase(_eventSet.begin());
        event->execute();
        cout << "event " << endl; 
        _hour = event->hour();
        delete event;
    }
}

bool EventComparator::operator()(const Event* event1, const Event* event2) const
{
    return (event1->hour() > event2->hour());
}
