#include "command.hpp"

bool versionCommand::execute()
{
    VERSION = "Version: 1.0";
    display();

    return true;
}

bool versionCommand::execute(std::string input)
{
    std::cout << "whoo" << std::endl;
}

void versionCommand::display()
{
    std::cout << VERSION << std::endl;
}

std::string versionCommand::getVersion()
{
    return VERSION;
}

void versionCommand::setVersion(std::string version)
{
    VERSION = version;
}
