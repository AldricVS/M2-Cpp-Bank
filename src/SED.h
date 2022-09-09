#if !defined(__SED_H__)
#define __SED_H__

#include <set>

#include "Event.h"

/**
 * @brief This class represent a discrete-event simulation
 * @author Nicolas CIBULKA
 * @since Thu Sep 08 2022
 */
class SED
{
private:
    std::set<Event*, EventComparator> _eventSet;

public:

    SED();

    ~SED();

    /**
     * @brief Add an event to the event queue
     * @param event
     * @return (void)
     */
    void add(Event& event);

    /**
     * @brief Execute the simulation
     * @return (void)
     */
    virtual void run() = 0;

    /**
     * @brief Get the simulation time
     * @return
     */
    virtual double hour() = 0;

};

/**
 * @brief This class allow us to compare two events
 * @author 
 * @since Fri Sep 09 2022
 */
class EventComparator{
    
    public:

    /**
     * @brief Override the operator () to compare events according to date
     * @param Event
     * @param event2
     * @return bool - true if event1 arrive after event2, false if not
     */
    bool operator()(const Event& event1, const Event& event2);
};

#endif // __SED_H__
