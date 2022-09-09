#if !defined(__BANK_H__)
#define __BANK_H__

#include <list>

#include "Cashier.h"
#include "WaitingList.h"
#include "SED.h"

/**
 * @brief Class that represent the Bank
 * @author
 * @since Thu Sep 08 2022
 */
class Bank : public SED
{

private:

    std::list<Cashier*> _cashierList;

    int _nbCashier;

    double _estimatedLength;

    double _realLength;

    double _averageArrivalTime;

    WaitingList _waitingList;

public:

    Bank(int nbCashier, double estimatedLength, std::list<double> cashierServiceTimes, double averageArrivalTime);

    ~Bank();

    double estimatedLength();

    int nbCashier();

    double timeBetweenArrival();

    double realLength();

    int nbClients();

    Cashier* firstFree();

};

// TODO créer une exception si le nombre de fichiers est pas valide

#endif // __BANK_H__
