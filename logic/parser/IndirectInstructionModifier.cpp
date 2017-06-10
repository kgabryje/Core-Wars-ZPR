
#include "IndirectInstructionModifier.h"

IndirectInstructionModifier::IndirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_B_INDIRECT)) {}

InstructionModifier *IndirectInstructionModifier::clone() const {
    return new IndirectInstructionModifier(*this);
}


boost::optional<Instruction>
IndirectInstructionModifier::findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) {
    boost::optional<Instruction> instr;
    mIndex += this->getValue();
    Instruction intermediateInstruction = memoryArray[*mIndex];
    mIndex += intermediateInstruction.getBValue();
    instr = memoryArray[*mIndex];
    return instr;

}
