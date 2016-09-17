#include "command.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <vector>

bool directoryCommand::execute()
{
    display();

    return true;
}

void directoryCommand::display()
{
    DIR *dp;
  struct dirent *ep;
  int counter = 1;
  int display = 0;
  std::vector<char*> files;
  files.clear();

  dp = opendir ("./");
  if (dp != NULL)
    {
      while (ep = readdir (dp))
      {
            files.push_back(ep->d_name);
      }
    (void) closedir (dp);
    }
  else
  {
    perror ("Couldn't open the directory");
  }

  //std::cout << files.size() << std::endl;

  int numOfFiles = files.size();
  char input = '\n';

  for(int j = 0; j < numOfFiles; j++)
  {
    if(j%10 == 0 )
    {
        std::cout << std::endl;
        std::cout << "Displaying " << j << " of " << numOfFiles << " files from working directory, press enter to continue." << std::endl;
        std::cout << "================================================================================" << std::endl;
        getchar();

    }
    else
    {
        std::cout << files.at(j) << std::endl;
    }

  }
}

bool directoryCommand::execute(std::string input)
{
    std::cout << "whoo" << std::endl;
}

