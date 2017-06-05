#ifndef CORE_WARS_ZPR_PROCESSMANAGER_H
#define CORE_WARS_ZPR_PROCESSMANAGER_H

#include <queue>

class ProcessManager {

public:
    ProcessManager(int firstProcess);

    void proceedToNextInstruction();

    void removeCurrentInstruction();

    void branchCurrentInstruction(int branchAddress);

    int getCurrentAddress();

    int getSize();

private:
    std::queue<int> processes;

};


#endif //CORE_WARS_ZPR_PROCESSMANAGER_H
