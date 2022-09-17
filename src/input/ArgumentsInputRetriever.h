#ifndef __ARGUMENTSINPUTRETRIEVER_H__
#define __ARGUMENTSINPUTRETRIEVER_H__

#include <map>
#include <list>
#include <stdexcept>

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

    /**
     * From the command line, create a map linking any argument to his value(s)
     * 
     * @returns a map with key = argument name and value = list of strings following the argument
     */
    std::map<std::string, std::list<std::string>> gatherArguments();

public:

    /**
     * Create the instance with the command line arguments provided by the useron program call.
     * 
     * This class is not responsible for handling this data : on destruction, the argv array will not be freed.
     */
    ArgumentsInputRetriever(int argc, char *argv[]);

    /**
     * @throw ParseException if an error occured while parsing the command line arguments.
     * @throw ArgumentNotFoundException if a wanted argument is not found.
     */
    Input retrieve();
};

class ParseException : public std::exception
{
public:
    const int argumentIndex;
    const std::string message;

    ParseException(int argumentIdx, std::string msg);

    const char* what() const noexcept;
};

class ArgumentNotFoundException : public std::exception
{
public:
    const std::string message;

    ArgumentNotFoundException(std::string msg);

    const char* what() const noexcept;
};

class InvalidArgumentException : public std::exception
{
public:
    const std::string message;

    InvalidArgumentException(std::string msg);

    const char* what() const noexcept;
};

#endif // __ARGUMENTSINPUTRETRIEVER_H__