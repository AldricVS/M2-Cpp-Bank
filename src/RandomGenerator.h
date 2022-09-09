#ifndef __RANDOMGENERATOR_H__
#define __RANDOMGENERATOR_H__

/**
 * @brief An abstract class with an internal state for generating numbers
 * @author 
 * @since Fri Sep 09 2022
 */
class RandomGenerator
{
public:
    RandomGenerator();

    /**
     * Returns the next number of the state in the double format.
     */
    virtual double nextDouble();
};

#endif // __RANDOMGENERATOR_H__