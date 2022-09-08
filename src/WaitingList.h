#if !defined(__WAITINGLIST_H__)
#define __WAITINGLIST_H__
#include "Client.h"
#include <list>

using namespace std;

class WaitingList{

    private:

    list<Client> _clientList;
    
    public:

    WaitingList();

    ~WaitingList();

    double averageLength();

    double maximumLength();

    double averageWaitingTime();

    void addClient(Client* client);

    bool isEmpty();

    Client removeFirst();
};

#endif // __WAITINGLIST_H__


