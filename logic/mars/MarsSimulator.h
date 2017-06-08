#ifndef CORE_WARS_ZPR_MARSSIMULATOR_H
#define CORE_WARS_ZPR_MARSSIMULATOR_H

#include <vector>
#include "Instruction.h"

class MarsSimulator {

public:
    void setInstructions(std::vector<Instruction> instructions);
    int doStuff();

private:
    int testCounter = 0;
    std::vector<Instruction> instructions;
};


#endif //CORE_WARS_ZPR_MARSSIMULATOR_H
