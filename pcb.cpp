#include "pcb.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>


PCB::PCB()
{
    int tempMem = rand() % 10000 + 1;
    int randPID = rand() % 10000 + 1;
    int out = rand() % 4;

    PID = randPID;
    CPU_Term = 0;
    IO_Term = 0;
    Wait_Term = 0;
    outcome = out;
    memory = tempMem;
    IO_Flag = -1;
}

int PCB::getPID()
{
    int pid = PID;
    return pid;
}
int PCB::getCPU()
{
    return CPU_Term;
}
int PCB::getIO()
{
    return IO_Term;
}
int PCB::getWait()
{
    return Wait_Term;
}

int PCB::getMemory()
{
    return memory;
}

int PCB::getOutcome()
{
    return outcome;
}
bool PCB::getIOFlag()
{
    return IO_Flag;
}

void PCB::setPID(int pid)
{
    PID = pid;
}
void PCB::setCPU(int cpu)
{
    CPU_Term = cpu;
}
void PCB::setIO(int io)
{
    IO_Term = io;
}
void PCB::setWait(int wait)
{
    Wait_Term = wait;
}
void PCB::setMemory(int mem)
{
    memory = mem;
}
void PCB::setIOFlag(bool event)
{
    IO_Flag = event;
}
void PCB::setOutcome(int rand)
{
    outcome = rand;
}
