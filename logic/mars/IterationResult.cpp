#include <iostream>
#include "IterationResult.h"


const std::vector<Instruction> IterationResult::getMemoryArray() const {
    return memoryArray;
}

void IterationResult::setMemoryArray(const std::vector<Instruction> memoryArray) {
    IterationResult::memoryArray = memoryArray;
}

const std::deque<MemoryIndex> IterationResult::getFirstWarriorProcessesIndexes() const {
    return firstWarriorProcessesIndexes;
}

void IterationResult::setFirstWarriorProcessesIndexes(const std::deque<MemoryIndex> firstWarriorProcessesIndexes) {
    std::cout << "tu?" << std::endl;
    IterationResult::firstWarriorProcessesIndexes = firstWarriorProcessesIndexes;
    std::cout << "czy tu?" << std::endl;
}

const std::deque<MemoryIndex> IterationResult::getSecondWarriorProcessesIndexes() const {
    return secondWarriorProcessesIndexes;
}

void IterationResult::setSecondWarriorProcessesIndexes(const std::deque<MemoryIndex> secondWarriorProcessesIndexes) {
    IterationResult::secondWarriorProcessesIndexes = secondWarriorProcessesIndexes;
}

const boost::optional<int> IterationResult::getLooser() const {
    return looser;
}

void IterationResult::setLooser(const boost::optional<int> looser) {
    IterationResult::looser = looser;
}

const std::string IterationResult::getPlayerName() const {
    return playerName;
}

void IterationResult::setPlayerName(const std::string playerName) {
    IterationResult::playerName = playerName;
}

const std::string IterationResult::getWarriorName() const {
    return warriorName;
}

void IterationResult::setWarriorName(const std::string warriorName) {
    IterationResult::warriorName = warriorName;
}
