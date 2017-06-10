#include <logic/parser/InstructionCreator.h>
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
        if (bFieldInstruction)
            return std::shared_ptr<OperationParams>(
                    new OperationParamsInstructions(*aFieldInstruction, *bFieldInstruction));
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

const std::vector<Instruction> MarsEngine::getMemoryArray() {
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
