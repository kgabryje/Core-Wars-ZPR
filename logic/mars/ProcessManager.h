#ifndef CORE_WARS_ZPR_PROCESSMANAGER_H
#define CORE_WARS_ZPR_PROCESSMANAGER_H

#include <queue>
#include "MemoryIndex.h"

/**
 * Class for managing processes
 */
class ProcessManager {

public:
    ProcessManager(int firstProcess);

    ProcessManager(MemoryIndex firstProcess);

    void jumpOver(int i);

    void proceedToNextInstruction();

    void removeCurrentInstruction();

    void branchCurrentInstruction(MemoryIndex branchAddress);

    void jumpFromCurrentInstruction(int jumpValue);

    MemoryIndex getCurrentAddress();

    int getSize();

private:
    std::queue<MemoryIndex> processes;

};


#endif //CORE_WARS_ZPR_PROCESSMANAGER_H
