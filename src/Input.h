#ifndef __INPUTRETRIEVER_H__
#define __INPUTRETRIEVER_H__

#include <list>
#include <stdexcept>

/**
 * @brief The structure containing all needed parameters for the simulation to run.
 * An instance of this structure created by an InputRetriever is garanteed to be valid.
 * @author 
 * @since Fri Sep 09 2022
 * @see InputRetriever
 */
class Input
{
public:
    const double expectedDuration;
    const int cashierCount;
    const std::list<double> averageTimes;
    const double averageArrivalTime;

    Input(double excpectedDur, int nbCashiers, std::list<double> averageTimeList, double averageArrivalTm);
};

/**
 * @brief Abstract class responsible for retrieving the user input and sending errors otherwise
 * @author 
 * @since Fri Sep 09 2022
 */
class InputRetriever
{
public:
    
    /**
     * Retrieve what the user want to set for the simulation.
     * This method is likely to throw an exception.
     */
    virtual Input retrieve(int argc, char *argv[]) = 0;
};

#endif // __INPUTRETRIEVER_H__