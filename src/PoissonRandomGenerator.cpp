#include "PoissonRandomGenerator.h"

PoissonRandomGenerator::PoissonRandomGenerator(double mean): _distribution(mean)
{}

PoissonRandomGenerator::~PoissonRandomGenerator()
{}

double PoissonRandomGenerator::nextDouble()
{
    return _distribution(_generator);   
}
