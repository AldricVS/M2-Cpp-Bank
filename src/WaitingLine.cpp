#include "WaitingLine.h"

WaitingLine::WaitingLine(Bank& bank) : _bank(&bank)
{}

double WaitingLine::averageLength()
{
    return _sumLengthPerStep / _stepCount;
}

double WaitingLine::maximumLength()
{
    return _maximumLength;
}

double WaitingLine::averageWaitingTime()
{
    return _totalWaitingTime / _bank->nbClients();
}

void WaitingLine::addClient(Client& client)
{
    
}

bool WaitingLine::isEmpty()
{
    
}

Client* WaitingLine::removeFirst()
{
    
}
