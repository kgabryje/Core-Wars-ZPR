#include "ProcessManager.h"

ProcessManager::ProcessManager(int firstProcess) {
    processes.push(MemoryIndex(firstProcess));
}

ProcessManager::ProcessManager(MemoryIndex firstProcess) {
    processes.push(firstProcess);
}

void ProcessManager::proceedToNextInstruction() {
    jumpOver(1);
}

void ProcessManager::jumpOver(int i) {
    MemoryIndex current = processes.front();
    current += i;
    processes.pop();
    processes.push(current);
}

void ProcessManager::branchCurrentInstruction(MemoryIndex branchAddress) {
    proceedToNextInstruction();
    processes.push(branchAddress);
}

void ProcessManager::removeCurrentInstruction() {
    processes.pop();
}


MemoryIndex ProcessManager::getCurrentAddress() {
    return processes.front();
}

int ProcessManager::getSize() {
    return processes.size();
}

void ProcessManager::jumpFromCurrentInstruction(int jumpValue) {
    jumpOver(jumpValue);
}


