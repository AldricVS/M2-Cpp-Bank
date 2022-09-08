#if !defined(__SED_H__)
#define __SED_H__

#include "Event.h"

/**
 * @brief This class represent a discrete-event simulation
 * @author Nicolas CIBULKA
 * @since Thu Sep 08 2022
 */
class SED{

    private:

    public:

    SED();

    ~SED();

    /**
     * @brief Add an event to the event queue
     * @param event
     * @return (void)
     */
    void add(Event event);

    /**
     * @brief Execute the simulation
     * @return (void)
     */
    void run();

    /**
     * @brief Get the simulation time
     * @return 
     */
    double hour();

};

#endif // __SED_H__
