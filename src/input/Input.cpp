#include "Input.h"

Input::Input(double excpectedDur, int nbCashiers, std::list<double> averageTimeList, double averageArrivalTm):
    expectedDuration(excpectedDur),
    cashierCount(nbCashiers),
    averageTimes(averageTimeList),
    averageArrivalTime(averageArrivalTm)
{}

Input retrieveInput(int argc, char *argv[])
{
    // TODO
    std::list<double> lst;
    return Input(0, 0, lst, 0);
}