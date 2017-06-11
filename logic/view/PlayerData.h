#ifndef CORE_WARS_ZPR_PLAYERDATA_H
#define CORE_WARS_ZPR_PLAYERDATA_H


#include <logic/mars/Instruction.h>

class PlayerData {
public:
    const std::vector<Instruction> &getInstructions() const;

    void setInstructions(const std::vector<Instruction> &instructions);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getWarriorName() const;

    void setWarriorName(const std::string &warriorName);

private:
    std::vector<Instruction> instructions;
    std::string name;
    std::string warriorName;
};


#endif //CORE_WARS_ZPR_PLAYERDATA_H
