#ifndef CORE_WARS_ZPR_PROCESSMANAGER_H
#define CORE_WARS_ZPR_PROCESSMANAGER_H

#include <queue>
#include "MemoryIndex.h"

class ProcessManager {

public:
    ProcessManager();
    ProcessManager(int firstProcess);

    ProcessManager(MemoryIndex firstProcess);

    void setFirstProcess(MemoryIndex firstProcess);

    void jumpOver(int i);

    void proceedToNextInstruction();

    void removeCurrentInstruction();

    void branchCurrentInstruction(MemoryIndex branchAddress);

    void jumpFromCurrentInstruction(int jumpValue);

    MemoryIndex getCurrentAddress();

    int getSize() const;

    const std::queue<MemoryIndex> &getProcesses() const;

private:
    std::queue<MemoryIndex> processes;

};


#endif //CORE_WARS_ZPR_PROCESSMANAGER_H
