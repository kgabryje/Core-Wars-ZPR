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
    boost::shared_ptr<OperationParams> params = mars.execute(mi);
    boost::shared_ptr<MarsOperation> addOper = mars.getOperation(mi);
    boost::shared_ptr<ProcessAction> res = params->accept(addOper);
    res->runAction(pm);
    return mars.getMemoryArray();

}

MarsSimulator::MarsSimulator() {

}

