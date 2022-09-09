#if !defined(__BANK_H__)
#define __BANK_H__

#include <list>

#include "Cashier.h"
#include "WaitingLine.h"
#include "SED.h"

/**
 * @brief The root of the simulation. This contains all methods relative to a bank and it's mechanics.
 * @author
 * @since Thu Sep 08 2022
 * @see SED
 */
class Bank : public SED
{

private:

    Cashier** _cashiers;

    int _nbCashier;

    double _estimatedLength;

    double _realLength;

    double _averageArrivalTime;

    WaitingLine _waitingLine;

public:

    Bank(int nbCashier, double estimatedLength, std::list<double> cashierServiceTimes, double averageArrivalTime);
    Bank(Bank& bank);
    ~Bank();

    Bank& operator=(const Bank& other);
    bool operator==(const Bank& other);

    double estimatedLength() const;

    int nbCashier() const;

    double timeBetweenArrival() const;

    double realLength() const;

    int nbClients() const;

    WaitingLine& waitingLine();

    Cashier* firstFree();

    void addToLine(Client* client);

    Client* getWaitingClient();

};

// TODO créer une exception si le nombre de fichiers est pas valide

#endif // __BANK_H__
