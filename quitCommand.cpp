#include "command.hpp"

bool quitCommand::execute()
{
    bool quitFlag = false;
    char input = ' ';

    std::cout << "Are you sure you want to quit? Press any key for yes or 'n' to stay in the shell." << std::endl;
    input = getchar();

    if(input == 'n')
    {
        quitFlag = true;
    }
    else
    {
        quitFlag = false;
    }

    return quitFlag;
}

bool quitCommand::execute(std::string input)
{
    std::cout << "whoo" << std::endl;
}
