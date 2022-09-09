#ifndef __BANK_H__
#define __BANK_H__

#include <list>

#include "Cashier.h"
#include "WaitingLine.h"
#include "SED.h"
#include "PoissonRandomGenerator.h"

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

    WaitingLine _waitingLine;

    double _averageArrivalTime;
    /**
     * The random generator used for computing next client arrival
     */
    PoissonRandomGenerator _arrivalTimeGenerator;
public:

    Bank(int nbCashier, double estimatedLength, std::list<double> cashierServiceTimes, double averageArrivalTime);
    Bank(Bank& bank);
    ~Bank();

    Bank& operator=(const Bank& other);
    bool operator==(const Bank& other);

    /**
     * Getter for the "estimatedLength" input
     */
    double estimatedLength() const;

    /**
     * Getter for the "nbCashier" input
     */
    int nbCashier() const;

    /**
     * Getter for the "average arrival time" input
     */
    double timeBetweenArrival() const;

    /**
     * 
     */
    double realLength() const;

    int nbClients() const;

    WaitingLine& waitingLine();

    Cashier* firstFree();

    void addToLine(Client* client);

    Client* getWaitingClient();

    double computeNextArrivalTime();

};

// TODO créer une exception si le nombre de fichiers est pas valide


#endif // __BANK_H__