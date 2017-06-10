#include "IterationResult.h"


const std::vector<Instruction> &IterationResult::getMemoryArray() const {
    return memoryArray;
}

void IterationResult::setMemoryArray(const std::vector<Instruction> &memoryArray) {
    IterationResult::memoryArray = memoryArray;
}

const std::deque<MemoryIndex> &IterationResult::getFirstWarriorProcessesIndexes() const {
    return firstWarriorProcessesIndexes;
}

void IterationResult::setFirstWarriorProcessesIndexes(const std::deque<MemoryIndex> &firstWarriorProcessesIndexes) {
    IterationResult::firstWarriorProcessesIndexes = firstWarriorProcessesIndexes;
}

const std::deque<MemoryIndex> &IterationResult::getSecondWarriorProcessesIndexes() const {
    return secondWarriorProcessesIndexes;
}

void IterationResult::setSecondWarriorProcessesIndexes(const std::deque<MemoryIndex> &secondWarriorProcessesIndexes) {
    IterationResult::secondWarriorProcessesIndexes = secondWarriorProcessesIndexes;
}
