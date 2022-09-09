#if !defined(__WAITINGLIST_H__)
#define __WAITINGLIST_H__

#include <queue>

#include "Client.h"


class WaitingList
{

private:

    std::queue<Client*> _queue;

public:

    WaitingList();

    ~WaitingList();

    // TODO : copy constructor, = & == overriding

    double averageLength();

    double maximumLength();

    double averageWaitingTime();

    void addClient(Client* client);

    bool isEmpty();

    Client* removeFirst();
};

#endif // __WAITINGLIST_H__


