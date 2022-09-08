#if !defined(__BANK_H__)
#define __BANK_H__

#include "Cashier.h"
#include "WaitingList.h"
#include "SED.h"

/**
 * @brief Class that represent the Bank
 * @author 
 * @since Thu Sep 08 2022
 */
class Bank : public SED{

    private:

    int _nbCashier;

    double _estimatedLength;

    double _averageArrivalTime;

    WaitingList _waitingList;

    public:

    Bank(int nbCashier, double estimatedLength, double* cashierServiceTime, double averageArrivalTime);

    ~Bank();

    double estimatedLength();

    int nbCashier();

    double timeBetweenArrival();

    double realLength();

    int nbClients();

    Cashier* firstFree();

};

#endif // __BANK_H__
