#include "DirectInstructionModifier.h"


DirectInstructionModifier::DirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_DIRECT)) {
}

InstructionModifier *DirectInstructionModifier::clone() const {
    return new DirectInstructionModifier(*this);
}

boost::optional<Instruction>
DirectInstructionModifier::findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) {
    boost::optional<Instruction> instr;
    mIndex += this->getValue();
    Instruction intermediateInstruction = memoryArray[*mIndex];
    intermediateInstruction.setLastMemoryIndex(*mIndex);
    //mIndex += intermediateInstruction.getBValue();
    //instr = memoryArray[*mIndex];

    // return instr;
    return intermediateInstruction;
}
