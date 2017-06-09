#include <logic/parser/InstructionCreator.h>
#include "MarsEngine.h"
#include "ProcessActionContinue.h"

const ProcessAction &MarsEngine::execute(MemoryIndex mIndex) {

    return ProcessActionContinue();
}

MarsEngine::MarsEngine() : memoryArray(MARSConstants::MEMORY_ARRAY_SIZE, InstructionCreator::createDefault()) {}

const std::vector<Instruction> MarsEngine::getMemoryArray() {
    return vector<Instruction>();
}
