#include "command.hpp"

bool aliasCommand::execute()
{
    std::cout << "whoo" << std::endl;
    return true;
}

bool aliasCommand::execute(std::string input)
{
    //std::vector<std::string> myCmds;
    //myCmds.clear();

    //myCmds = splitInput(input);

    return true;
}


std::vector<std::string> aliasCommand::splitInput(std::string command)
{
    std::vector<std::string> splitCommands;
    int spaceCounter = 0;
    splitCommands.clear();
    std::string oldCmd = "";
    std::string alias = "";
    std::string tempWord = "";

    std::cout << command << std::endl;
    std::cout << command.size() << std::endl;
    std::cout << command.at(4) << std::endl;

    for(int i = 0; i < command.size(); i++)
    {
        if(command.at(i) == ' ')
        {
            if(spaceCounter == 1)
            {
                oldCmd = tempWord;
                splitCommands.push_back(oldCmd);
                tempWord = "";
            }
            else if(spaceCounter == 2)
            {
                alias = tempWord;
                splitCommands.push_back(alias);
                i = command.size();
                break;
            }
            else
            {
                spaceCounter++;
                tempWord = "";
            }

        }
        else
        {
            tempWord = tempWord + command.at(i);
        }
    }

    return splitCommands;
}
