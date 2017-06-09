#include <logic/parser/InstructionCreator.h>
#include "MarsEngine.h"
#include "OperationParamsInstructions.h"
#include "OperationParamsMixed.h"

const OperationParams &MarsEngine::execute(MemoryIndex mIndex) {
    Instruction instrToExecute = memoryArray[*mIndex];
    boost::optional<Instruction> aFieldInstruction = instrToExecute.getAddressA()->findTargetInstruction(mIndex,
                                                                                                         getMemoryArray());
    boost::optional<Instruction> bFieldInstruction = instrToExecute.getAddressB()->findTargetInstruction(mIndex,
                                                                                                         getMemoryArray());
    if (aFieldInstruction)
        if (bFieldInstruction)
            return OperationParamsInstructions(*aFieldInstruction, *bFieldInstruction);
        else
            return OperationParamsMixed(instrToExecute.getBValue(), *aFieldInstruction);
    else if (bFieldInstruction)
        return OperationParamsMixed(instrToExecute.getAValue(), *bFieldInstruction);
    else
        throw ("Unimplemented OperationParams(int,int)");
}

MarsEngine::MarsEngine() : memoryArray(MARSConstants::MEMORY_ARRAY_SIZE, InstructionCreator::createDefault()) {
}

const std::vector<Instruction> MarsEngine::getMemoryArray() {
    return memoryArray;
}