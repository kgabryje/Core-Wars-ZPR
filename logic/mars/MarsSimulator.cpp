#include <iostream>
#include "MarsSimulator.h"

void MarsSimulator::setInstructions(
        std::vector<Instruction> instructions) {
    this->instructions = instructions;

}

int MarsSimulator::doStuff() {
    return testCounter++;
}
