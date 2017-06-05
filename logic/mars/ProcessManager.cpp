#include "ProcessManager.h"

void ProcessManager::proceedToNextInstruction() {
    int current = processes.front();
    current++;
    processes.pop();
    processes.push(current);
}

void ProcessManager::branchCurrentInstruction(int branchAddress) {
    int current = processes.front();
    current++;
    processes.pop();
    processes.push(branchAddress);
    processes.push(current);
}

void ProcessManager::removeCurrentInstruction() {
    processes.pop();
}

ProcessManager::ProcessManager(int firstProcess) {
    processes.push(firstProcess);
}

int ProcessManager::getCurrentAddress() {
    return processes.front();
}

int ProcessManager::getSize() {
    return processes.size();
}
