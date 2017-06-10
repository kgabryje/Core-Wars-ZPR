#ifndef CORE_WARS_ZPR_MARSSIMULATOR_H
#define CORE_WARS_ZPR_MARSSIMULATOR_H

#include <vector>
#include "Instruction.h"
#include "MarsEngine.h"

class MarsSimulator {

public:
    MarsSimulator();

    void setInstructions(std::vector<Instruction> instructions);

    std::vector<Instruction> doStuff();

private:
    int beginAddress = 10;
    MarsEngine mars = MarsEngine();
    ProcessManager pm = ProcessManager(beginAddress);
};


#endif //CORE_WARS_ZPR_MARSSIMULATOR_H
