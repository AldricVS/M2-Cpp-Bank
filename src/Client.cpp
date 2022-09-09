#include "Client.h"

Client::Client(double arrivalTime): _arrivalTime(arrivalTime)
{
    
}

Client::~Client()
{
    
}

double Client::ArrivalTime()
{
    return _arrivalTime;
}
