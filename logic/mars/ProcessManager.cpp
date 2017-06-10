#include "ProcessManager.h"

/**
 * Creates and adds process
 * @param firstProcess
 */
ProcessManager::ProcessManager(int firstProcess) {
    processes.push(MemoryIndex(firstProcess));
}

/**
 * Adds process
 * @param firstProcess
 */
ProcessManager::ProcessManager(MemoryIndex firstProcess) {
    processes.push(firstProcess);
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
    processes.pop();
    processes.push(current);
}

/**
 * Starts a new process from address branchAddress
 * @param branchAddress address of new process
 */
void ProcessManager::branchCurrentInstruction(MemoryIndex branchAddress) {
    proceedToNextInstruction();
    processes.push(branchAddress);
}

/**
 * Removes current instruction
 */
void ProcessManager::removeCurrentInstruction() {
    processes.pop();
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
int ProcessManager::getSize() {
    return processes.size();
}

/**
 * Jumps jumpValue instructions forward
 * @param jumpValue
 */
void ProcessManager::jumpFromCurrentInstruction(int jumpValue) {
    jumpOver(jumpValue);
}


