#ifndef CORE_WARS_ZPR_ITERATIONRESULT_H
#define CORE_WARS_ZPR_ITERATIONRESULT_H


#include "Instruction.h"

class IterationResult {
public:

    const std::vector<Instruction> &getMemoryArray() const;

    void setMemoryArray(const std::vector<Instruction> &memoryArray);

    const std::deque<MemoryIndex> &getFirstWarriorProcessesIndexes() const;

    void setFirstWarriorProcessesIndexes(const std::deque<MemoryIndex> &firstWarriorProcessesIndexes);

    const std::deque<MemoryIndex> &getSecondWarriorProcessesIndexes() const;

    void setSecondWarriorProcessesIndexes(const std::deque<MemoryIndex> &secondWarriorProcessesIndexes);

private:
    std::vector<Instruction> memoryArray;
    std::deque<MemoryIndex> firstWarriorProcessesIndexes;
    std::deque<MemoryIndex> secondWarriorProcessesIndexes;
};


#endif //CORE_WARS_ZPR_ITERATIONRESULT_H
