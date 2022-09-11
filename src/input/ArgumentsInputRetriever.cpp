#include "ArgumentsInputRetriever.h"

#include "Input.h"

ArgumentsInputRetriever::ArgumentsInputRetriever(int argc, char *argv[]) : InputRetriever()
{
    _argc = argc;
    _argv = argv;
}

Input ArgumentsInputRetriever::retrieve()
{
    // TODO
    std::list<double> lst;
    return Input(0, 0, lst, 0);
}
