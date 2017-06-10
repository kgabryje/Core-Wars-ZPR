#include <iostream>
#include <boost/shared_ptr.hpp>
#include "MarsSimulator.h"

void MarsSimulator::setInstructions(
        std::vector<Instruction> instructions) {
    mars.enterWarrior(beginAddress, instructions);
    pm = ProcessManager(beginAddress);
}

std::vector<Instruction> MarsSimulator::doStuff() {
    MemoryIndex mi = pm.getCurrentAddress();
    std::shared_ptr<OperationParams> params = mars.execute(mi);
    std::shared_ptr<MarsOperation> addOper = mars.getOperation(mi);
    std::shared_ptr<ProcessAction> res = params->accept(addOper);
    res->runAction(pm);
    return mars.getMemoryArray();

}

MarsSimulator::MarsSimulator() {

}

