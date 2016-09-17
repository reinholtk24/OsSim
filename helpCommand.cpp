#include "command.hpp"

bool helpCommand::execute()
{
    bool flag = true;
    flag = display();

    return true;
}

bool helpCommand::execute(std::string input)
{
    std::cout << "whoo" << std::endl;

    return true;
}

bool helpCommand::display()
{
    bool loopHelp = true;

    while(loopHelp == true)
    {
        std::string userInput = " ";

        std::cout << "You have entered the help menu. Enter X at any time to exit." << std::endl;
        std::cout << "help-- :" << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "Commands                        | Explanations                                 |" << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cout << "quit                            | Exits the simulator" << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "version                         | Displays the operating system version" << std:: endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "date                            | Displays the date and time of the current day" << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "alias <old cmd> <new cmd>       | Type alias for more information" << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "help                            | Displays a help menu explaining each command" << std::endl;
         std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "directory                       | Prints the contents of the working directory" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        std::cout << "batch <path/to/file.ext>        | Executes multiple commands from a batch file" << std::endl;
        std::cout << "================================================================================" << std::endl;
        std::cin >> userInput;

        for(int i = 0; i < 51; i++)
        {
            std::cout << std::endl;
        }

        if(userInput == "X")
        {
            loopHelp = false;
        }
        else if(userInput == "alias")
        {
            std::string input = "";
            std::cout << "Alias Help" << std::endl;
            std::cout << "The command 'alias' allows you to change an existing system command into a new one." << std::endl;
            std::cout << "To correctly run the alias instruction, provide the name of the current command and what you want the command to be changed to. For example: " <<std::endl;
            std::cout << "alias quit exit" << std::endl;
            std::cout << "This command would replace the quit command with the exit command. Exit now has the same functionality that quit had before the command ran." << std::endl;
            std::cout << "Press any enter to return to help menu." << std::endl;
            std::cin >> input;
            for(int i = 0; i < 51; i++)
            {
                std::cout << std::endl;
            }
        }
        else
        {
            //do nothing
        }
    }
    loopHelp = true;

    return loopHelp;
}
