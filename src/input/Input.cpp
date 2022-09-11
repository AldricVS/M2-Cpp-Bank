#include "Input.h"

#include "InputRetriever.h"

Input::Input(double excpectedDur, int nbCashiers, std::list<double> averageTimeList, double averageArrivalTm):
    expectedDuration(excpectedDur),
    cashierCount(nbCashiers),
    averageTimes(averageTimeList),
    averageArrivalTime(averageArrivalTm)
{}

/**
 * Depending on the implementation to use 
 */
InputRetriever* createRetriever(int argc, char *argv[])
{

}

Input retrieveInput(int argc, char *argv[])
{
    // Find the implementation to use
    // TODO
    std::list<double> lst;
    return Input(0, 0, lst, 0);
}