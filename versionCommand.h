#ifndef VERSIONCOMMAND_H
#define VERSIONCOMMAND_H
#include <iostream>
#include "command.hpp"

class versionCommand : public Command
{
public:
    virtual void execute();
    void display();
private:
    std::string VERSION;
};
#endif //VERSIONCOMMAND_H
