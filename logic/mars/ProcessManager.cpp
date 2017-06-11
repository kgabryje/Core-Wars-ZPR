#include "ProcessManager.h"

/**
 * Creates and adds process
 * @param firstProcess
 */
ProcessManager::ProcessManager(int firstProcess) {
    processes.push_back(MemoryIndex(firstProcess));
}


/**
 * Adds process
 * @param firstProcess
 */
ProcessManager::ProcessManager(MemoryIndex firstProcess) {
    processes.push_back(firstProcess);
}

/**
 * Skips to next instruction
 */
void ProcessManager::proceedToNextInstruction() {
    jumpOver(1);
}

/**
 * Jumps i instructions ahead
 * @param i number of instructions to jump over
 */
void ProcessManager::jumpOver(int i) {
    MemoryIndex current = processes.front();
    current += i;
    processes.pop_front();
    processes.push_back(current);
}

/**
 * Starts a new process from address branchAddress
 * @param branchAddress address of new process
 */
void ProcessManager::branchCurrentInstruction(MemoryIndex branchAddress) {
    proceedToNextInstruction();
    processes.push_back(branchAddress);
}

/**
 * Removes current instruction
 */
void ProcessManager::removeCurrentInstruction() {
    processes.pop_front();
}


/**
 * Returns address of current process
 * @return
 */
MemoryIndex ProcessManager::getCurrentAddress() {
    return processes.front();
}

/**
 * Returns number of processes
 * @return number of processes
 */
int ProcessManager::getSize() const {
    return processes.size();
}

/**
 * Jumps jumpValue instructions forward
 * @param jumpValue
 */
void ProcessManager::jumpFromCurrentInstruction(int jumpValue) {
    jumpOver(jumpValue);
}

void ProcessManager::setFirstProcess(MemoryIndex firstAddress) {
    processes = std::deque<MemoryIndex>();
    processes.push_back(firstAddress);

}

ProcessManager::ProcessManager() {

}

const std::deque<MemoryIndex> ProcessManager::getProcesses() const {
    return processes;
}


