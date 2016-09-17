#ifndef PCBCOMMANDHANDLER_H
#define PCBCOMMANDHANDLER_H
#include "pcb.h"
#include "ioevent.h"
#include <vector>
#include <iostream>

class PCBCommandHandler
{
public:
    PCBCommandHandler();
    int getMaxMemory();
    bool executeCommand(int index);
    bool validPID(int pid);
    bool createPCB();  // 8
    bool deletePCB(); // 9
    bool blockPCB(); // 10
    bool unblockPCB(); // 11
    bool showPCB(); // 12
    bool showAllPCB(); // 13
    bool showReadyPCB(); // 14
    bool showBlockedPCB(); // 15
    bool generateRandomPCB(); // 16
    bool executePCB(); // 17
    void cleanIO();
    void swapPlaces(int swapper, int swappie);

private:
    int maxMemory;
    std::vector<PCB*> ready;
    std::vector<PCB*> blocked;
    std::vector<PCB*> CPU;
    std::vector<IOEvent*> IO_events;
    std::vector<PCB*> allPCBs;
    std::vector<int> PID_list;


};
#endif //PCBCOMMANDHANDLER_H
