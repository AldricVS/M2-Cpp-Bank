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
private:
    int _argc;
    char** _argv;

public:

    /**
     * Create the instance with the command line arguments provided by the useron program call.
     * 
     * This class is not responsible for handling this data : on destruction, the argv array will not be freed.
     */
    ArgumentsInputRetriever(int argc, char *argv[]);

    Input retrieve();
};

#endif // __ARGUMENTSINPUTRETRIEVER_H__