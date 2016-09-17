
#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>

class Command
{
public:
    virtual bool execute() = 0;
    virtual bool execute(std::string input) = 0;
};

class versionCommand : public Command
{
public:
    bool execute();
    bool execute(std::string input);
    void display();
    std::string getVersion();
    void setVersion(std::string version);
private:
    std::string VERSION;
};

class helpCommand : public Command
{
public:
    bool execute();
    bool execute(std::string input);
    bool display();
};

class quitCommand : public Command
{
public:
    bool execute();
    bool execute(std::string input);
};

class directoryCommand : public Command
{
public:
    bool execute();
    void display();
    bool execute(std::string input);
};

class dateCommand : public Command
{
public:
    bool execute();
    void changeDate();
    void display();
    bool execute(std::string input);
private:
    std::string DATE;
};

class historyCommand : public Command
{
public:
    bool execute();
    bool execute(std::string input);
};

class aliasCommand : public Command
{
public:
    bool execute(std::string input);
    bool execute();
    std::vector<std::string> splitInput(std::string command);
};

#endif // COMMAND_H
