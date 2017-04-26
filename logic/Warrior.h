#ifndef CORE_WARS_ZPR_WARRIOR_H
#define CORE_WARS_ZPR_WARRIOR_H

#include <logic/mars/Instruction.h>
#include <vector>


class Warrior {
private:
    std::string name;
    std::vector<Instruction> instructions;
public:
    Warrior(std::string &basic_string, std::vector<Instruction> vector);
};


#endif //CORE_WARS_ZPR_WARRIOR_H