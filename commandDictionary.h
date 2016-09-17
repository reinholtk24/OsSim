#ifndef COMMANDDICTIONARY_H
#define COMMANDDICTIONARY_H
#include "command.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

class CommandDictionary
{
    public:
        CommandDictionary(void);
        ~CommandDictionary();
        Command* getCmdObj(std::string userInput);
        int getCmdCode(std::string input);
        void addNewEntry(std::string oldCommand, std::string newCommand);
    private:
        std::unordered_map<std::string, int> commandCodes;
};
#endif //

