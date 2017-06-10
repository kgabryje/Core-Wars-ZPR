#ifndef CORE_WARS_ZPR_MARSSIMULATOR_H
#define CORE_WARS_ZPR_MARSSIMULATOR_H

#include <vector>
#include "Instruction.h"
#include "MarsEngine.h"

class MarsSimulator {

public:
    MarsSimulator();

    void setWarriors(std::vector<Instruction> instructions);

    std::vector<Instruction> doStuff();

private:
    MarsEngine mars;
    ProcessManager firstWarriorManager;
    ProcessManager secondWarriorManager;

    void setWarrior(std::vector<Instruction> instructions, ProcessManager &warriorManager);

    int getRandomMemoryAddress();

    void doIteration(ProcessManager &warriorManager);
};


#endif //CORE_WARS_ZPR_MARSSIMULATOR_H
