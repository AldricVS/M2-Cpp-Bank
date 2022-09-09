#if !defined(__CASHIER_H__)
#define __CASHIER_H__

#include "Client.h"

/**
 * @brief Modelisation of a Cashier that will serve clients during a defined average service time.
 * @author Nicolas CIBULKA
 * @since Thu Sep 08 2022
 */
class Cashier
{

private:
    double _averageServiceTime;

    /// @brief Can be null.
    Client* client;

public:

    Cashier(double averageServiceTime);
    ~Cashier();

    double averageServiceTime();

    int nbClients();

    double OccupationRate();

    bool isFree();

    void serve(Client* client);

    void wait();
};

#endif // __CASHIER_H__
