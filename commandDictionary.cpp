#include "commandDictionary.h"

CommandDictionary::CommandDictionary(void)
{
    commandCodes["date"] = 0;
    commandCodes["version"] = 1;
    commandCodes["help"] = 2;
    commandCodes["directory"] = 3;
    commandCodes["quit"] = 4;
    commandCodes["history"] = 5;
    commandCodes["alias"] = 6;
    commandCodes["batch"] = 7;
    commandCodes["createpcb"] = 8;
    commandCodes["deletepcb"] = 9;
    commandCodes["blockpcb"] = 10;
    commandCodes["unblockpcb"] = 11;
    commandCodes["showpcb"] = 12;
    commandCodes["showallpcb"] = 13;
    commandCodes["showreadypcb"] = 14;
    commandCodes["showblockedpcb"] = 15;
    commandCodes["generatepcb"] = 16;
    commandCodes["executepcb"] = 17;
}

CommandDictionary::~CommandDictionary()
{
    std::cout << "Destroying Dictionary" << std::endl;
}

void CommandDictionary::addNewEntry(std::string oldCommand, std::string newCommand)
{
    switch(getCmdCode(oldCommand))
    {
        case 0:
            commandCodes[newCommand] = 0;
        break;
        case 1:
            commandCodes[newCommand] = 1;
        break;
        case 2:
            commandCodes[newCommand] = 2;
        break;
        case 3:
            commandCodes[newCommand] = 3;
        break;
        case 4:
            commandCodes[newCommand] = 4;
        break;
        case 5:
            commandCodes[newCommand] = 5;
        break;
        case 6:
            commandCodes[newCommand] = 6;
        break;
        case 7:
            commandCodes[newCommand] = 7;
        break;
        default:
            std::cout << "Command is invalid." << std::endl;
        break;
    }
}

int CommandDictionary::getCmdCode(std::string input)
{
    int code = -1;

    if(commandCodes.count(input)>0)
    {
        code = commandCodes[input];
    }
    else
    {
        code = -1;
    }

    return code;
}
