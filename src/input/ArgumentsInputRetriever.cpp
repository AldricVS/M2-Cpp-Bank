#include "ArgumentsInputRetriever.h"

#include "Input.h"

ArgumentsInputRetriever::ArgumentsInputRetriever()
{}

Input ArgumentsInputRetriever::retrieve(int argc, char *argv[])
{
    // TODO
    std::list<double> lst;
    return Input(0, 0, lst, 0);
}
