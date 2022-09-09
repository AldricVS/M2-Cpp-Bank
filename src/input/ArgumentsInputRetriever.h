#ifndef __ARGUMENTSINPUTRETRIEVER_H__
#define __ARGUMENTSINPUTRETRIEVER_H__

#include "InputRetriever.h"

/**
 * @brief The CLI-based version of the input retriever : the user have already put all needed arguments in the command
 * @author 
 * @since Fri Sep 09 2022
 */
class ArgumentsInputRetriever : public InputRetriever
{
public:
    ArgumentsInputRetriever();

    Input retrieve(int argc, char *argv[]);
};

#endif // __ARGUMENTSINPUTRETRIEVER_H__