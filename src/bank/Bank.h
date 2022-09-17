#ifndef __BANK_H__
#define __BANK_H__

#include <list>
#include <stdexcept>

#include "Cashier.h"
#include "WaitingLine.h"
#include "../event/SED.h"
#include "../random/PoissonRandomGenerator.h"

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
     * @brief Run the simulation
     * @return (void)
     */
    void run();

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

    int nbClientsServed() const;

    WaitingLine& waitingLine();

    Cashier* firstFree();

    void addToLine(Client* client);

    Client* getWaitingClient();

    double computeNextArrivalTime();

    void displaySimulationDatas();

    void setRealLength(double hour);

};

class InvalidTimeNumberException : public std::exception {
    public:

    const int _nbCashier;

    const int _nbServiceTime;

    InvalidTimeNumberException(int nbCashier, int nbServiceTime): _nbCashier(nbCashier), _nbServiceTime(nbServiceTime){};
};


#endif // __BANK_H__