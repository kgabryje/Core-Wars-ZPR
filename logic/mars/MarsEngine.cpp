#include <logic/parser/InstructionCreator.h>
#include <iostream>
#include "MarsEngine.h"
#include "OperationParamsInstructions.h"
#include "OperationParamsMixed.h"

std::shared_ptr<OperationParams> MarsEngine::execute(MemoryIndex mIndex) {
    Instruction instrToExecute = memoryArray[*mIndex];
    boost::optional<Instruction> aFieldInstruction = instrToExecute.getAddressA()->findTargetInstruction(mIndex,
                                                                                                         getMemoryArray());
    boost::optional<Instruction> bFieldInstruction = instrToExecute.getAddressB()->findTargetInstruction(mIndex,
                                                                                                         getMemoryArray());
    if (aFieldInstruction)
        if (bFieldInstruction) {
            std::cout << "MarsEngine OperationParamsInstructions creation" << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : first instruction: "
                      << aFieldInstruction->getOperation()->getOpCode() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : first instr a val" << aFieldInstruction->getAValue()
                      << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : first instr b val" << aFieldInstruction->getBValue()
                      << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : second instr"
                      << bFieldInstruction->getOperation()->getOpCode() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : second instr a val" << bFieldInstruction->getAValue()
                      << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : second instr a val" << bFieldInstruction->getBValue()
                      << std::endl;

            std::shared_ptr<OperationParams> in =
                    std::shared_ptr<OperationParams>(
                            new OperationParamsInstructions(*aFieldInstruction, *bFieldInstruction));

            std::cout << "-----------\n\n" << std::endl;
            OperationParamsInstructions *i = dynamic_cast<OperationParamsInstructions *> (in.get());
            std::cout << "MarsEngine OperationParamsInstructions : first instr"
                      << i->getFirstInstruction().getOperation()->getOpCode() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : first instr a val"
                      << i->getFirstInstruction().getAValue() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : first instr b val"
                      << i->getFirstInstruction().getBValue() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : second instr"
                      << i->getSecondInstruction().getOperation()->getOpCode() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : second instr a val"
                      << i->getSecondInstruction().getAValue() << std::endl;
            std::cout << "MarsEngine OperationParamsInstructions : second instr a val"
                      << i->getSecondInstruction().getBValue() << std::endl;
            std::cout << "*******\n\n" << std::endl;
            return in;
        }
        else
            return std::shared_ptr<OperationParams>(
                    new OperationParamsMixed(instrToExecute.getBValue(), *aFieldInstruction));
    else if (bFieldInstruction)
        return std::shared_ptr<OperationParams>(
                new OperationParamsMixed(instrToExecute.getAValue(), *bFieldInstruction));
    else
        throw ("Unimplemented OperationParams(int,int)");
}

MarsEngine::MarsEngine() : memoryArray(MARSConstants::MEMORY_ARRAY_SIZE, InstructionCreator::createDefault()) {
}

const std::vector<Instruction> &MarsEngine::getMemoryArray() {
    return memoryArray;
}

void MarsEngine::enterWarrior(int beginAddres, vector<Instruction> warrior) {
    MemoryIndex index(beginAddres);
    for (int i = 0; i < warrior.size(); i++)
        memoryArray[*index++] = warrior[i];
}

std::shared_ptr<MarsOperation> MarsEngine::getOperation(MemoryIndex index) {
    Instruction i = memoryArray[*index];
    return i.getOperation();
}

void MarsEngine::editMemoryArray(const std::vector<Instruction> instructionsToModify) {
    for (int i = 0; i < instructionsToModify.size(); i++) {
        std::cout << "Inserting : " << instructionsToModify[i].getOperation().get()->getOpCode() << " at "
                  << instructionsToModify[i].getLastMemoryIndex() << std::endl;
        memoryArray.insert(memoryArray.begin() + instructionsToModify[i].getLastMemoryIndex(), instructionsToModify[i]);
        std::cout << "Result : "
                  << memoryArray[instructionsToModify[i].getLastMemoryIndex()].getOperation().get()->getOpCode()
                  << std::endl;
    }


}
