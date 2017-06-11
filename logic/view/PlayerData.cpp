#include "PlayerData.h"

const std::vector<Instruction> &PlayerData::getInstructions() const {
    return instructions;
}

void PlayerData::setInstructions(const std::vector<Instruction> &instructions) {
    PlayerData::instructions = instructions;
}

const std::string &PlayerData::getName() const {
    return name;
}

void PlayerData::setName(const std::string &name) {
    PlayerData::name = name;
}

const std::string &PlayerData::getWarriorName() const {
    return warriorName;
}

void PlayerData::setWarriorName(const std::string &warriorName) {
    PlayerData::warriorName = warriorName;
}
