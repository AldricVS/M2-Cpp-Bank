#include "InteractiveInputRetriever.h"

#include "Input.h"

InteractiveInputRetriever::InteractiveInputRetriever()
{
    
}

Input InteractiveInputRetriever::retrieve(int argc, char *argv[])
{
    // TODO
    std::list<double> lst;
    return Input(0, 0, lst, 0);
}
