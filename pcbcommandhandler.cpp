#include "pcbcommandhandler.h"
#include "pcb.h"
#include "ioevent.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool compare(int one, int two);

PCBCommandHandler::PCBCommandHandler()
{
    ready.clear();
    blocked.clear();
    IO_events.clear();
    CPU.clear();
    PID_list.clear();
    allPCBs.clear();

    maxMemory = 0;
}

int PCBCommandHandler::getMaxMemory()
{
    int MAX_MEMORY = 0;
    int memory = 0;

    std::string line = "";
    std::ifstream memfile("memory/memory.txt");

    while(getline(memfile, line))
    {
        std::stringstream convert(line);
        convert >> memory;
        MAX_MEMORY = memory;
    }

    maxMemory = MAX_MEMORY;

    return MAX_MEMORY;
}

 bool PCBCommandHandler::executeCommand(int index)
 {
    switch(index)
    {
        case 8:
            createPCB();
        break;
        case 9:
            deletePCB();
        break;
        case 10:
            blockPCB();
        break;
        case 11:
            unblockPCB();
        break;
        case 12:
            showPCB();
        break;
        case 13:
            showAllPCB();
        break;
        case 14:
            showReadyPCB();
        break;
        case 15:
            showBlockedPCB();
        break;
        case 16:
            generateRandomPCB();
        break;
        case 17:
            executePCB();
        break;
        default:
        break;
    }
 }
 bool PCBCommandHandler::validPID(int pid)
 {
    bool validFlag = true;

    for(int i = 0; i < PID_list.size(); i++)
    {
        if(pid == PID_list.at(i))
        {
            validFlag = false;
            break;
        }
        else
        {
            validFlag = true;
        }
    }

    return validFlag;
 }

 bool PCBCommandHandler::createPCB()  // 8
 {
    int processID = 0;
    std::string pid = "";
    std::string mem = "";
    int memoryNeeded = 0;
    bool PIDvalid = false;
    bool memValid = false;

    std::cout << "You have chosen to create a new PCB." << std::endl;

    while(PIDvalid == false)
    {
        std::cout << "Please enter a process ID for the PCB." << std::endl;
        std::cin >> pid;

        std::stringstream convert(pid);
        convert >> processID;

        if(validPID(processID) == true)
        {
            PIDvalid = true;
        }
        else
        {
            std::cout << "Your PID must be unique. Please try again." << std::endl;
            PIDvalid = false;
        }
    }

    while(memValid == false)
    {
        std::cout << "Please enter the memory needed for this PCB" << std::endl;
        std::cin >> mem;

        std::stringstream convert(mem);
        convert >> memoryNeeded;

        if(memoryNeeded < 1)
        {
            std::cout << "You did not allocate any memory for this PCB." << std::endl;
            memValid = false;
        }
        else if(memoryNeeded > 2000000000)
        {
            std::cout << "This PCB exceeds the maximum amount of memory available for a PCB." << std::endl;
            memValid = false;
        }
        else
        {
            PCB* newPCB = new PCB();
            newPCB->setPID(processID);
            newPCB->setMemory(memoryNeeded);
            ready.push_back(newPCB);
            PID_list.push_back(processID);
            allPCBs.push_back(newPCB);
            memValid = true;
        }
    }

    return true;

 }

bool PCBCommandHandler::deletePCB() // 9
{
    bool deleteFlag = false;
    int PID = 0;
    std::string userInput = "";
    int queueOfPCB = 0;

    std::cout << "Please enter the PID of the PCB you would like to delete." << std::endl;
    std::cin >> userInput;

    std::stringstream convert3(userInput);
    convert3 >> PID;

    for(int i = 0; i < allPCBs.size();i++)
    {
        std::cout << PID << std::endl;
        std::cout << allPCBs.at(i)->getPID() << std::endl;
        if(PID == allPCBs.at(i)->getPID())
        {
            deleteFlag = true;
            queueOfPCB = 0;
            delete allPCBs.at(i);
            allPCBs.erase(allPCBs.begin()+i);
            break;
        }
        else
        {
            deleteFlag = false;
        }
    }

    if(deleteFlag == true)
    {
        std::cout << "The PCB has been located and deleted from existence." << std::endl;

        switch(queueOfPCB)
        {
            case 1:
                for(int i = 0; i < ready.size();i++)
                {
                    if(PID == ready.at(i)->getPID())
                    {
                        delete ready.at(i);
                        ready.erase(ready.begin()+i);
                    }
                }
            break;
            case 2:
                for(int j = 0; j < blocked.size();j++)
                {
                    if(PID == blocked.at(j)->getPID())
                    {
                        delete blocked.at(j);
                        blocked.erase(blocked.begin()+j);
                    }
                }
            break;
            default:
            break;
        }
    }
    else
    {
        std::cout << "The PID you entered was invalid." << std::endl;
    }

    return deleteFlag;
}
bool PCBCommandHandler::blockPCB() // 10
{
    bool blockFlag = false;
    int PID = 0;
    std::string userInput = "";
    int queueOfPCB = 0;

    std::cout << "Please enter the PID of the PCB you would like to block." << std::endl;
    std::cin >> userInput;

    std::stringstream convert3(userInput);
    convert3 >> PID;

    for(int i = 0; i < ready.size();i++ )
    {
        if(PID == ready.at(i)->getPID())
        {
            PCB* temp;
            temp = ready.at(i);
            ready.erase(ready.begin()+i);
            blocked.push_back(temp);
            blockFlag = true;
            break;
        }
        else
        {
            blockFlag = false;
        }
    }

    if(blockFlag == true)
    {
        std::cout << "The PCB with PID " << PID << " has been moved to the blocked queue." << std::endl;
    }
    else
    {
        std::cout << "There was an error moving the PCB into the blocked queue, it may not exist." << std::endl;
    }

    return blockFlag;
}

bool PCBCommandHandler::unblockPCB() // 11
{
    bool readyFlag = false;
    int PID = 0;
    std::string userInput = "";
    int queueOfPCB = 0;

    std::cout << "Please enter the PID of the PCB you would like to block." << std::endl;
    std::cin >> userInput;

    std::stringstream convert3(userInput);
    convert3 >> PID;

    for(int i = 0; i < blocked.size();i++ )
    {
        if(PID == blocked.at(i)->getPID())
        {
            PCB* temp;
            temp = blocked.at(i);
            blocked.erase(blocked.begin()+i);
            ready.push_back(temp);
            readyFlag = true;
            break;
        }
        else
        {
            readyFlag = false;
        }
    }

    if(readyFlag == true)
    {
        std::cout << "The PCB with PID " << PID << " has been moved to the ready queue." << std::endl;
    }
    else
    {
        std::cout << "There was an error moving the PCB into the ready queue, it may not exist." << std::endl;
    }

    return readyFlag;
}
bool PCBCommandHandler::showPCB() // 12
{

    bool showFlag = false;
    int PID = 0;
    std::string userInput = "";
    int queueOfPCB = 0;

    std::cout << "Please enter the PID for the PCB you want to know more about." << std::endl;
    std::cin >> userInput;

    std::stringstream convert3(userInput);
    convert3 >> PID;

    for(int pcb = 0; pcb < allPCBs.size(); pcb++)
    {
        if(PID == allPCBs.at(pcb)->getPID())
        {
            std::cout << "PCB-->PID[ " << allPCBs.at(pcb)->getPID() << " ] CPU_TERM[ "<< \
            allPCBs.at(pcb)->getCPU() << " ] IO_TERM[ " << allPCBs.at(pcb)->getIO() << " ] Wait_TERM[ " << \
            allPCBs.at(pcb)->getWait() << " ] Memory[ " << allPCBs.at(pcb)->getMemory() << " ]" << std::endl;
            showFlag = true;
            break;
        }
        else
        {
            showFlag = false;
        }
    }

    if(showFlag == false)
    {
        std::cout << "The PCB you are looking for does not exist." << std::endl;
    }
    else
    {
        //do nothing
    }

    return showFlag;
}
bool PCBCommandHandler::showAllPCB() // 13
{
    for(int i = 0; i < allPCBs.size(); i++)
    {
        for(int j=allPCBs.size()-1; j>i; j--)
        {
            if(compare(allPCBs[j]->getPID(),allPCBs[j-1]->getPID()))
            {
                swapPlaces(j, j-1);
            }
        }
    }

    for(int pcb = 0; pcb < allPCBs.size(); pcb++)
    {
        std::cout << pcb+1 <<". PCB-->PID[ " << allPCBs.at(pcb)->getPID() << " ] CPU_TERM[ "<< \
            allPCBs.at(pcb)->getCPU() << " ] IO_TERM[ " << allPCBs.at(pcb)->getIO() << " ] Wait_TERM[ " << \
            allPCBs.at(pcb)->getWait() << " ] Memory[ " << allPCBs.at(pcb)->getMemory() << " ]" << std::endl;
    }

    return true;

}
bool PCBCommandHandler::showReadyPCB() // 14
{
    for(int pcb = 0; pcb < ready.size(); pcb++)
    {
        std::cout << pcb+1 <<". PCB-->PID[ " << ready.at(pcb)->getPID() << " ] CPU_TERM[ "<< \
            ready.at(pcb)->getCPU() << " ] IO_TERM[ " << ready.at(pcb)->getIO() << " ] Wait_TERM[ " << \
            ready.at(pcb)->getWait() << " ] Memory[ " << ready.at(pcb)->getMemory() << " ]" << std::endl;
    }

    return true;
}

bool PCBCommandHandler::showBlockedPCB() // 15
{

    for(int pcb = 0; pcb < blocked.size(); pcb++)
    {
        std::cout << pcb+1 <<". PCB-->PID[ " << blocked.at(pcb)->getPID() << " ] CPU_TERM[ "<< \
            blocked.at(pcb)->getCPU() << " ] IO_TERM[ " << blocked.at(pcb)->getIO() << " ] Wait_TERM[ " << \
            blocked.at(pcb)->getWait() << " ] Memory[ " << blocked.at(pcb)->getMemory() << " ]" << std::endl;
    }

    return true;
}
bool PCBCommandHandler::generateRandomPCB() // 16
{
    bool randFlag = false;
    int PID = 0;
    std::string userInput = "";
    int queueOfPCB = 0;

    std::cout << "Please input the number of PCBs you would like to randomly generate." << std::endl;
    std::cin >> userInput;

    std::stringstream convert3(userInput);
    convert3 >> PID;

    for(int pcb = 0; pcb < PID; pcb++)
    {
        PCB* newPCB = new PCB();
        ready.push_back(newPCB);
        PID_list.push_back(newPCB->getPID());
        allPCBs.push_back(newPCB);
        randFlag = true;
    }

    return randFlag;
}


bool PCBCommandHandler::executePCB() //17
{
    if(ready.size() == 0)
    {
        //do nothing
    }
    else
    {
        std::ofstream output;
        bool flag = true;
        int readySize = ready.size();
        int curWaitTime = 0;
        int totalWaitTime = 0;
        int outcome= 0;
        int cpuTime = 0;
        int eventTime = 0;
        int totalTimeCycles = 0;
        int ioEvent = 0;


        output.open("execution_trace.txt");
        while(flag == true)
        {
            if(readySize == 0)
            {
                flag = false;
                break;
            }
            else
            {
                // next 3 lines pops the front of the ready queue and saves it in head
                PCB *curProcess = new PCB();
                curProcess = ready[0];
                ready.erase(ready.begin()+0);
                readySize--;

                cpuTime = rand() % 10000 + 1;

                curProcess->setCPU(cpuTime);
                CPU.push_back(curProcess);
                output << "Inserting Process: " << curProcess->getPID() << " into CPU. \n";
                for(int j = 0; j < readySize; j++)
                {
                    curWaitTime = ready.at(j)->getWait();
                    totalWaitTime = curWaitTime + cpuTime;
                    ready.at(j)->setWait(totalWaitTime);
                }

                for(int i = 0; i < cpuTime; i++)
                {
                    totalTimeCycles = totalTimeCycles + i;
                    if((i % 10) == 0 )
                    {
                        ioEvent = rand() % 10 + 1;
                        if(ioEvent == 4)
                        {
                            IOEvent* userInput = new IOEvent();
                            userInput->setTime(totalTimeCycles);
                            userInput->setType(0); // 0 means userInput
                            IO_events.push_back(userInput);
                        }
                        else if(ioEvent == 9)
                        {
                            IOEvent* hardDrive = new IOEvent();
                            hardDrive->setTime(totalTimeCycles);
                            hardDrive->setType(1); // 1 means hardDrive
                            IO_events.push_back(hardDrive);
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

                curProcess->setOutcome(rand()%4);
                outcome = curProcess->getOutcome();

                switch(outcome)
                {
                    case 0: //process terminates
                        std::cout << "Process Finished -->PID[ " << curProcess->getPID() << " ] CPU_TERM[ "<< \
                        curProcess->getCPU() << " ] IO_TERM[ " << curProcess->getIO() << " ] \n\t\t\t Wait_TERM[ " << \
                        curProcess->getWait() << " ] Memory[ " << curProcess->getMemory() << " ]" << std::endl;
                        output << " \t\t\t -----Process Terminated-----\n\t\t\t PID [" << curProcess->getPID() << " ] CPU_TERM[ "<< \
                        curProcess->getCPU() << " ] IO_TERM[ " << curProcess->getIO() << " ] \n\t\t\t Wait_TERM[ " << \
                        curProcess->getWait() << " ] Memory[ " << curProcess->getMemory() << " ]\n";
                    break;
                    case 1: // process pushed onto ready queue
                        output << "\t\t\t\t----Process moved to ready queue----\n";
                        ready.push_back(curProcess);
                        readySize++;
                    break;
                    case 2: // blocked q user input
                        output << "\t\t\t\t+---Process Blocked: Awaiting user input---+\n";
                        curProcess->setIOFlag(0);
                        blocked.push_back(curProcess);
                    break;
                    case 3: // blocked q hard drive request
                        output << "\t\t\t\t+---Process Blocked: Awaiting hard drive request---+\n";
                        curProcess->setIOFlag(1);
                        blocked.push_back(curProcess);
                    break;
                }

                int eventSize = IO_events.size();
                int blockedSize = blocked.size();
                if(eventSize == 0 )
                {
                    //do nothing
                }
                else
                {
                    for(int k = 0; k < eventSize; k++)
                    {
                        for(int l = 0; l < blockedSize; l++)
                        {
                            eventTime = eventTime + 1;
                            if(IO_events[k]->getTime() < blocked[l]->getWait())
                            {
                                IO_events.erase(IO_events.begin()+k);
                                eventSize--;
                            }
                            else if(IO_events[k]->getEvent() == blocked[l]->getIOFlag() && IO_events[k]->getTime() > blocked[l]->getWait())
                            {
                                output << "\t\t\t\t\t +--I/O Event located--+  Moving Process into Ready Queue...\n";

                                PCB *temp = new PCB();
                                temp = blocked[l];
                                blocked[l]->setIO(eventTime);
                                eventTime = blocked[l]->getWait() + eventTime;
                                blocked[l]->setWait(eventTime);
                                ready.push_back(temp);
                                readySize++;
                                blocked.erase(blocked.begin()+l);
                                IO_events.erase(IO_events.begin()+k);
                                eventSize--;
                                blockedSize--;
                            }
                            else
                            {
                                IO_events.erase(IO_events.begin()+k);
                                eventSize--;
                            }
                        }
                    }
                    IO_events.clear();
                    eventTime = 0;

                }
            }
            CPU.pop_back();
            output << "\t\t\t\t\t #Process Removed From CPU#\n";
        }
    output.close();

    }
    allPCBs.clear();
}

bool compare(int one, int two)
{
    if(one < two)
    {
        return true;
    }
    else if( one == two)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PCBCommandHandler::swapPlaces(int swapper, int swappie)
{
    PCB* temp;
    temp = allPCBs[swappie];
    allPCBs[swappie] = allPCBs[swapper];
    allPCBs[swapper] = temp;
}




