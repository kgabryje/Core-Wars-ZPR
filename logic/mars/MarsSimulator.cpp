#include <iostream>
#include "MarsSimulator.h"

void MarsSimulator::setInstructions(
        std::vector<std::shared_ptr<Instruction>> instructions) {
    this->instructions = instructions;
    for (auto const &instr: instructions)
        instr.get()->test();
}

int MarsSimulator::doStuff() {
    return testCounter++;
}
