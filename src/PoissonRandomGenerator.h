#ifndef __POISSONRANDOMGENERATOR_H__
#define __POISSONRANDOMGENERATOR_H__

#include <random>

#include "RandomGenerator.h"

/**
 * @brief Implementation of the {@link RandomGenerator} following the Poisson's law
 * @author
 * @since Fri Sep 09 2022
 * @see RandomGenerator
 */
class PoissonRandomGenerator : public RandomGenerator
{
private:
    std::default_random_engine _generator;
    std::poisson_distribution<double> _distribution;

public:

    PoissonRandomGenerator(double mean);
    ~PoissonRandomGenerator();

    /**
     * Returns the next number of the state in the double format.
     */
    double nextDouble();
};

#endif // __POISSONRANDOMGENERATOR_H__