#if !defined(__WAITINGLIST_H__)
#define __WAITINGLIST_H__

#include <queue>

#include "Bank.h"
#include "Client.h"


class WaitingList
{

private:
    Bank* bank;
    std::queue<Client*> _queue;

public:

    WaitingList(Bank& bank);

    ~WaitingList();

    // TODO : copy constructor, = & == overriding

    double averageLength();

    double maximumLength();

    double averageWaitingTime();

    void addClient(Client& client);

    bool isEmpty();

    Client* removeFirst();
};

#endif // __WAITINGLIST_H__


