#include "ProcessManager.h"

ProcessManager::ProcessManager(int firstProcess) {
    processes.push_back(MemoryIndex(firstProcess));
}

ProcessManager::ProcessManager(MemoryIndex firstProcess) {
    processes.push_back(firstProcess);
}

void ProcessManager::proceedToNextInstruction() {
    jumpOver(1);
}

void ProcessManager::jumpOver(int i) {
    MemoryIndex current = processes.front();
    current += i;
    processes.pop_front();
    processes.push_back(current);
}

void ProcessManager::branchCurrentInstruction(MemoryIndex branchAddress) {
    proceedToNextInstruction();
    processes.push_back(branchAddress);
}

void ProcessManager::removeCurrentInstruction() {
    processes.pop_front();
}


MemoryIndex ProcessManager::getCurrentAddress() {
    return processes.front();
}

int ProcessManager::getSize() const {
    return processes.size();
}

void ProcessManager::jumpFromCurrentInstruction(int jumpValue) {
    jumpOver(jumpValue);
}

void ProcessManager::setFirstProcess(MemoryIndex firstAddress) {
    processes = std::deque<MemoryIndex>();
    processes.push_back(firstAddress);

}

ProcessManager::ProcessManager() {

}

const std::deque<MemoryIndex> &ProcessManager::getProcesses() const {
    return processes;
}


