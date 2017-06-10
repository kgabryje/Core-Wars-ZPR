#include <iostream>
#include <boost/shared_ptr.hpp>
#include "MarsSimulator.h"
#include "OperationParamsInstructions.h"

void MarsSimulator::setInstructions(
        std::vector<Instruction> instructions) {
    mars.enterWarrior(beginAddress, instructions);
    pm = ProcessManager(beginAddress);
}

std::vector<Instruction> MarsSimulator::doStuff() {
    std::cout << "TestMars1" << std::endl;
    MemoryIndex mi = pm.getCurrentAddress();
    std::cout << "TestMars2" << std::endl;
    std::cout << "MarsSimulator OperationParamsInstructions  from function" << std::endl;


    OperationParamsInstructions *cons1 = dynamic_cast<OperationParamsInstructions *> (mars.execute(mi).get());
    if (cons1 != nullptr) {
        std::cout << "obiekt prosto z funkcji" << std::endl;
        std::cout << "jest typu OperationParamsInstructions" << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : first instr"
                  << cons1->getFirstInstruction().getOperation()->getOpCode() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : first instr a val"
                  << cons1->getFirstInstruction().getAValue() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : first instr b val"
                  << cons1->getFirstInstruction().getBValue() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : second instr"
                  << cons1->getSecondInstruction().getOperation()->getOpCode() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : second instr a val"
                  << cons1->getSecondInstruction().getAValue() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : second instr a val"
                  << cons1->getSecondInstruction().getBValue() << std::endl;
    }

    std::shared_ptr<OperationParams> params = mars.execute(mi);


    std::cout << "MarsSimulator OperationParamsInstructions  after creation" << std::endl;
    OperationParamsInstructions *cons = dynamic_cast<OperationParamsInstructions *> (params.get());
    if (cons != nullptr) {
        std::cout << "jest typu OperationParamsInstructions" << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : first instr"
                  << cons->getFirstInstruction().getOperation()->getOpCode() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : first instr a val"
                  << cons->getFirstInstruction().getAValue() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : first instr b val"
                  << cons->getFirstInstruction().getBValue() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : second instr"
                  << cons->getSecondInstruction().getOperation()->getOpCode() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : second instr a val"
                  << cons->getSecondInstruction().getAValue() << std::endl;
        std::cout << "MarsSimulator OperationParamsInstructions : second instr a val"
                  << cons->getSecondInstruction().getBValue() << std::endl;
    }

    std::cout << "TestMars3" <<
              std::endl;
    std::shared_ptr<MarsOperation> addOper = mars.getOperation(mi);
    std::cout << "TestMars4" <<
              std::endl;
    OperationResult res = params->accept(addOper);
    std::cout << "TestMars5" <<
              std::endl;
    res.getPrecessAction()->runAction(pm);
    std::cout << "TestMars6" <<
              std::endl;
    std::cout << "Instrukcji do zmiany:" << res.getInstructions().size() << std::endl;
    for (Instruction i: res.getInstructions()) {
        std::cout << "instrukcja do zmiany:"
                  << i.getOperation()->getOpCode() << std::endl;
        std::cout << "instrukcja do zmiany pod adresem :"
                  << i.getLastMemoryIndex() << std::endl;
        std::cout
                << i.getAValue() << std::endl;
        std::cout
                << i.getBValue() << std::endl;
    }
    mars.editMemoryArray(res.getInstructions());

    return mars.getMemoryArray();

}

MarsSimulator::MarsSimulator() {

}

