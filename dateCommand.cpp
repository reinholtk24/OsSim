#include "command.hpp"

bool dateCommand::execute()
{
     DATE = __TIMESTAMP__;
     display();

     return true;
}

bool dateCommand::execute(std::string input)
{
    std::cout << "whoo" << std::endl;
}

void dateCommand::display()
{
    std::cout << "Today is: " + DATE << std::endl;
}
