#if !defined(__WAITINGLIST_H__)
#define __WAITINGLIST_H__

#include <queue>
#include <list>

#include "Bank.h"
#include "Client.h"



/**
 * @brief The lin
 * @author  
 * @since Fri Sep 09 2022
 */
class WaitingLine
{

private:
    Bank* _bank;
    std::queue<Client*> _queue;

    /**
     * For each client arrival / departure, the current length of the queue will be added to the list.
     * This is used for the computation of the average length.
     */
    unsigned int sumLengthperStep;

    unsigned int stepCount;
    
public:

    WaitingLine(Bank& bank);

    double averageLength();

    double maximumLength();

    double averageWaitingTime();

    void addClient(Client& client);

    bool isEmpty();

    Client* removeFirst();
};

#endif // __WAITINGLIST_H__


