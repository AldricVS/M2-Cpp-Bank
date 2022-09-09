#include "WaitingLine.h"

#include "Bank.h"

WaitingLine::WaitingLine(Bank& bank) : _bank(&bank)
{}

WaitingLine::~WaitingLine()
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

void WaitingLine::updateLengthAttributes()
{
    int currentLength = _queue.size();
    _sumLengthPerStep += currentLength;
    _stepCount++;
    if (currentLength > _maximumLength)
    {
        _maximumLength = currentLength;
    }
}

void WaitingLine::addClient(Client& client)
{
    _queue.push(&client);
    updateLengthAttributes();
}

bool WaitingLine::isEmpty()
{
    return _queue.empty();
}

Client* WaitingLine::removeFirst()
{
    if (isEmpty())
    {
        return nullptr;
    }

    Client* client = _queue.front();
    _queue.pop();

    updateLengthAttributes();

    return client;
}
