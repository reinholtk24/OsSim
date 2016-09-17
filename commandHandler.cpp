#include "commandHandler.h"
#include "command.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//gordo wrote ALL this
//not kyle

CommandHandler::CommandHandler()
{
    commands.clear();
    cmdHistory.clear();

    dateCommand* date = new dateCommand;
    versionCommand* version = new versionCommand;
    helpCommand* help = new helpCommand;
    directoryCommand* directory = new directoryCommand;
    quitCommand* quit = new quitCommand;
    historyCommand* history = new historyCommand;
    aliasCommand* alias = new aliasCommand;

    commands.push_back(date);
    commands.push_back(version);
    commands.push_back(help);
    commands.push_back(directory);
    commands.push_back(quit);
    commands.push_back(history);
    commands.push_back(alias);
}
CommandHandler::~CommandHandler()
{
    std::cout << " " << std::endl;
}

void CommandHandler::storeCommand(std::string command)
{
    this->cmdHistory.push_back(command);

}

bool CommandHandler::executeCommand(std::string userCommand)
{
    int index = -1;
    bool returnStatus = true;
    std::string systemCmd = "";
    std::vector<std::string> aliasCmds;
    std::vector<std::string> batchCmds;
    aliasCmds.clear();
    batchCmds.clear();

    storeCommand(userCommand);

    systemCmd = parseCmd(userCommand);
    index = cmdDict.getCmdCode(systemCmd);

    if(index < 0)
    {
        std::cout << "'" << userCommand << "' is an invalid command." << std::endl;
    }
    else if(index == 5)
    {
        displayHistory();
    }
    else if(index == 6)
    {
        aliasCmds = splitInput(userCommand);

        if(aliasCmds.size() != 2)
        {
            std::cout << "Improper syntax for alias command." << std::endl;
        }
        else
        {
            cmdDict.addNewEntry(aliasCmds[0],aliasCmds[1]);
        }
    }
    else if(index == 7)
    {
        std::string file = "";
        std::string line = "";
        std::string tempToken = "";

        int numOfCommands = 0;

        std::vector<std::string> cmds;

        batchCmds = splitInputBatch(userCommand);

        if(batchCmds.size() != 2)
        {
            std::cout << "Improper syntax for batch command. batch <filename>" << std::endl;
            //do nothing
        }
        else
        {
            file = batchCmds.at(1);
            std::ifstream infile(file.c_str());

            while(getline(infile, line))
            {
                for(int j = 0; j < line.size(); j++)
                {
                    if(line.at(j) == ' ' || line.at(j) == '\n')
                    {
                        if(tempToken.size() < 1)
                        {
                            break;
                        }
                        else
                        {
                            cmds.push_back(tempToken);
                            tempToken = "";
                        }
                    }
                    else
                    {
                        tempToken = tempToken + line.at(j);
                    }
                }
            }
            ///Print the contents of cmds vector /*
            /*
            for(int k = 0; k < cmds.size(); k++)
            {
                //std::cout << cmds.at(k) << "  --size = " << cmds.at(k).size() << std::endl;
            }
            */
            numOfCommands = countCommands(cmds); // countCommands also executes all of the valid commands in from the batch file

            std::cout << "Number of commands in batch file executed  -----> " << numOfCommands << std::endl;

            infile.close();
        }
    }
    else if(index > 7)
    {
        PCBController.executeCommand(index);
    }
    else
    {
        returnStatus = commands.at(index)->execute();
    }

    return returnStatus;
}

void CommandHandler::displayHistory()
{
    int totalcmds = cmdHistory.size();
    char myInput = ' ';
    std::string history = "";
    int backspaces = 0;

    for(int j = totalcmds; j > 0; j--)
    {
        history = cmdHistory.at(j-1);

        std::cout << history;

        myInput = getchar();

        std::cin.clear();
        backspaces = history.size();

        for(int k = backspaces; k < 0; k++)
        {
            printf("\b");
        }
        printf("\r");
    }
}

std::string CommandHandler::parseCmd(std::string cmd)
{
    std::string possibleCmd = "";

    if (cmd.find("alias") != std::string::npos)
    {
        possibleCmd = "alias";
    }
    else if(cmd.find("batch") != std::string::npos)
    {
        possibleCmd = "batch";
    }
    else
    {
        possibleCmd = cmd;
    }

    return possibleCmd;
}

std::vector<std::string> CommandHandler::splitInput(std::string command)
{
    std::vector<std::string> splitCommands;
    int spaceCounter = 0;
    splitCommands.clear();
    std::string oldCmd = "";
    std::string alias = "";
    std::string tempWord = "";

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
            if(i == (command.size()-1))
            {
                alias = tempWord + command.at(i);
                splitCommands.push_back(alias);
                i = command.size();
                break;
            }
            else
            {
                tempWord = tempWord + command.at(i);
            }
        }
    }

    if(splitCommands.size() < 1)
    {
        splitCommands.clear();
    }

    return splitCommands;
}

std::vector<std::string> CommandHandler::splitInputBatch(std::string command)
{
    std::vector<std::string> splitCommands;
    int spaceCounter = 0;
    splitCommands.clear();
    std::string batch = "";
    std::string file = "";
    std::string tempWord = "";

    for(int i = 0; i < command.size(); i++)
    {
        if(command.at(i) == ' ')
        {
            if(spaceCounter == 0)
            {
                batch = tempWord;
                splitCommands.push_back(batch);
                tempWord = "";
                spaceCounter++;
            }
            else if(spaceCounter == 1)
            {
                file = tempWord;
                splitCommands.push_back(file);
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
            if(i == (command.size()-1))
            {
                file = tempWord + command.at(i);
                splitCommands.push_back(file);
                i = command.size();
                break;
            }
            else
            {
                tempWord = tempWord + command.at(i);
            }
        }
    }

    if(splitCommands.size() < 1)
    {
        splitCommands.clear();
    }

    return splitCommands;
}

int CommandHandler::countCommands(std::vector<std::string> commands)
{
    std::string currentCommand = "";
    int cmdIndex = -1;
    int cmdCounter = 0;

    for(int l = 0; l < commands.size(); l++)
    {
        cmdIndex = -1;
        if(commands.at(l) == "/")
        {
            //do nothing
        }
        else if (commands.at(l) == "version" || commands.at(l) == "date" || commands.at(l) == "quit" || commands.at(l) == "help" || commands.at(l) == "history")
        {
            cmdIndex = cmdDict.getCmdCode(commands.at(l));
            this->commands.at(cmdIndex)->execute();
            cmdCounter++;
        }
        else if(commands.at(l) == "alias")
        {
            if(commands.size() == (l+1) )
            {
                std::cout << "Invalid alias command in batch file." << std::endl;
            }
            else if(commands.size() == (l+2))
            {
                std::cout << "Invalid alias command in batch file." << std::endl;
            }
            else if( commands.size() == (l+3) || commands.at(l+1) != "/" || commands.at(l+2) != "/" )
            {
                cmdDict.addNewEntry(commands.at(l+1),commands.at(l+2));
                cmdCounter++;
                l = l+3;
            }
            else
            {
                std::cout << "Invalid alias command in batch file." << std::endl;
            }
        }
    }

    return cmdCounter;
}
