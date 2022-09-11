#ifndef __INTERACTIVEINPUTRETRIEVER_H__
#define __INTERACTIVEINPUTRETRIEVER_H__

#include "InputRetriever.h"

/**
 * @brief The interactive version of the input retriever : the user will be asked several questions to fill the input structure.
 * @author 
 * @since Fri Sep 09 2022
 */
class InteractiveInputRetriever : public InputRetriever
{
public:
    InteractiveInputRetriever();

    Input retrieve();
};

#endif // __INTERACTIVEINPUTRETRIEVER_H__