#ifndef PCB_H
#define PCB_H

class PCB
{
public:
    PCB();
    int getPID();
    int getCPU();
    int getIO();
    int getWait();
    int getMemory();
    int getOutcome();
    bool getIOFlag();
    void setPID(int pid);
    void setCPU(int cpu);
    void setIO(int io);
    void setIOFlag(bool event);
    void setWait(int wait);
    void setMemory(int mem);
    void setOutcome(int rand);
private:
    int PID;
    int CPU_Term;
    int IO_Term;
    int Wait_Term;
    int memory;
    int outcome;
    bool IO_Flag;
};

#endif // PCB_H
