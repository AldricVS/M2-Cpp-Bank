#include "Input.h"

Input::Input(double excpectedDur, int nbCashiers, std::list<double> averageTimeList, double averageArrivalTm):
    expectedDuration(excpectedDur),
    cashierCount(nbCashiers),
    averageTimes(averageTimeList),
    averageArrivalTime(averageArrivalTm)
{}