#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H
#include <string>
#include <vector>
#include <queue>
#include "command.hpp"
#include "commandDictionary.h"
#include "pcb.h"
#include "pcbcommandhandler.h"

class CommandHandler
{
public:
    CommandHandler();
    ~CommandHandler();
    bool executeCommand(std::string userCommand);
    void storeCommand(std::string command);
    void displayHistory();
    std::string parseCmd(std::string userCommand);
    std::vector<std::string> splitInput(std::string command);
    std::vector<std::string> splitInputBatch(std::string command);
    int countCommands(std::vector<std::string> commands);
private:
    std::vector<std::string> cmdHistory;
    std::vector<Command*> commands;
    CommandDictionary cmdDict;
    PCBCommandHandler PCBController;
};
#endif //COMMANDHANDLER_H
