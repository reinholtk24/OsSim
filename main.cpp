#include <iostream>
#include "command.hpp"
#include "commandDictionary.h"
#include "commandHandler.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::string trim(std::string& str);

int main()
{
    srand (time(NULL));
    std::string userInput = "a";

    std::cout << " __      __       .__" << std::endl;
    std::cout << "/  \\    /  \\ ____ |  |   ____  ____   _____   ____" << std::endl;
    std::cout << "\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ "  << std::endl;
    std::cout << " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/" << std::endl;
    std::cout <<  "  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >" << std::endl;
    std::cout <<   "       \\/       \\/          \\/            \\/     \\/" << std::endl;

    std::cout << std::endl;
    CommandHandler controller;

    bool flag = true;

    while(flag == true)
    {
        if(userInput == "" || userInput == " " || userInput == "\n\r" || userInput == "\r\n" || userInput == "\n" || userInput == "\r")
        {
            userInput = "aaa";
        }
        else
        {
            std::cout << "user@osSim ~$: ";
            getline(std::cin,userInput);
            std::cin.clear();

            if(userInput.size() > 0)
            {
                userInput = trim(userInput);
            }

            flag = controller.executeCommand(userInput);
        }

         std::cin.ignore(1,'\n');

    }

	return 0;
}


std::string trim(std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}


