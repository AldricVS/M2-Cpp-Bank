#include "ArgumentsInputRetriever.h"

#include <sstream>

#include "Input.h"

using namespace std;

ArgumentsInputRetriever::ArgumentsInputRetriever(int argc, char *argv[]) : InputRetriever()
{
    _argc = argc;
    _argv = argv;
}

double findExpectedDuration(map<string, list<string>>& map)
{
    list<string> l = map["-d"];
    if (l.empty())
    {
        throw ArgumentNotFoundException("Cannot find 'duration' (-d) parameter");
    }
    string s = l.front();
    double duration = stod(s);
    if (duration <= 0.0)
    {
        throw InvalidArgumentException("Duration must be greater than 0");
    }
    return duration;
}

int findCashierCount(map<string, list<string>>& map)
{
    list<string> l = map["-c"];
    if (l.empty())
    {
        throw ArgumentNotFoundException("Cannot find 'cashierCount' (-c) parameter");
    }
    string s = l.front();
    int cashierCount = stoi(s);
    if (cashierCount <= 0.0)
    {
        throw InvalidArgumentException("Cashier count must be greater than 0");
    }
    return cashierCount;
}

double findAverageArrivalTime(map<string, list<string>>& map)
{
    list<string> l = map["-a"];
    if (l.empty())
    {
        throw ArgumentNotFoundException("Cannot find 'average arrival time' (-a) parameter");
    }
    string s = l.front();
    double time = stod(s);
    if (time <= 0.0)
    {
        throw InvalidArgumentException("Average arrival time must be greater than 0");
    }
    return time;
}

list<double> findCashiersAverageTimes(map<string, list<string>>& map, int cashierCount)
{
    list<string> l = map["-t"];
    if (l.empty())
    {
        throw ArgumentNotFoundException("Cannot find 'cashiers average time' (-t) parameter");
    }
    list<double> times;
    for (std::list<string>::iterator it = l.begin(); it != l.end(); it++)
    {
        string s = *it;
        times.push_back(stod(s));
    }
    if (times.size())
    {
        throw InvalidArgumentException("The number of times provided is not the same as the number of cashiers set");
    }
    return times;
}

Input ArgumentsInputRetriever::retrieve()
{
    map<string, list<string>> map = gatherArguments();

    double exceptedDuration = findExpectedDuration(map);
    int cashierCount = findCashierCount(map);
    list<double> averageTimes = findCashiersAverageTimes(map, cashierCount);
    double arrivalTime = findAverageArrivalTime(map);

    return Input(exceptedDuration, cashierCount, averageTimes, arrivalTime);
}

map<string, list<string>> ArgumentsInputRetriever::gatherArguments()
{
    string *currentArg = nullptr;
    map<string, list<string>> map;
    for (int i = 0; i < _argc; i++)
    {
        string arg = _argv[i];
        
        // If it is an arg name, we will create a map for it
        if (arg[0] == '-')
        {
            // Map will be default-constructed on first [] call, no need to insert it by hand
            currentArg = &arg;
        } else 
        {
            // We should already have a current arg
            if (currentArg == nullptr)
            {
                throw ParseException(i, "Expected an argument name (with a '-') before encountering this");
            }
            map[*currentArg].push_back(arg);
        }
    }
    return map;
}

ParseException::ParseException(int argumentIdx, std::string msg):
    argumentIndex(argumentIdx),
    message(msg)
{
}

const char* ParseException::what()
{
    stringstream ss;
    ss << message << " (at argument n°" << argumentIndex << ")";
    return ss.str().c_str();
}

ArgumentNotFoundException::ArgumentNotFoundException(std::string msg):
    message(msg)
{}

const char* ArgumentNotFoundException::what()
{
    return message.c_str();
}

InvalidArgumentException::InvalidArgumentException(std::string msg):
    message(msg)
{}

const char* InvalidArgumentException::what()
{
    return message.c_str();
}