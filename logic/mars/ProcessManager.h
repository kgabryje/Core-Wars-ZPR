#ifndef CORE_WARS_ZPR_PROCESSMANAGER_H
#define CORE_WARS_ZPR_PROCESSMANAGER_H

#include <queue>
#include "MemoryIndex.h"

class ProcessManager {

public:
    ProcessManager(int firstProcess);

    ProcessManager(MemoryIndex firstProcess);

    void proceedToNextInstruction();

    void removeCurrentInstruction();

    void branchCurrentInstruction(MemoryIndex branchAddress);

    MemoryIndex getCurrentAddress();

    int getSize();

private:
    std::queue<MemoryIndex> processes;

};


#endif //CORE_WARS_ZPR_PROCESSMANAGER_H
