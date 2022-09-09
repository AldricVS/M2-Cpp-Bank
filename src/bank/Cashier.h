#ifndef __CASHIER_H__
#define __CASHIER_H__

#include "Client.h"
#include "../random/PoissonRandomGenerator.h"

class Bank;

/**
 * @brief Modelisation of a Cashier that will serve clients during a defined average service time.
 * @author Nicolas CIBULKA
 * @since Thu Sep 08 2022
 */
class Cashier
{

private:
    Bank* _bank;
    double _averageServiceTime;
    int _nbClientsServed;
    double _workingTime;
    PoissonRandomGenerator _randomGenerator;

    /// @brief Can be null.
    Client* _client;

public:

    Cashier(Bank& bank, double averageServiceTime);
    ~Cashier();

    double averageServiceTime() const;

    int nbClients() const;

    double OccupationRate();

    bool isFree();

    void serve(Client* client);

    void wait();
};


#endif // __CASHIER_H__