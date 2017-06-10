
#include "IndirectInstructionModifier.h"

IndirectInstructionModifier::IndirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_B_INDIRECT)) {}

boost::shared_ptr<InstructionModifier> IndirectInstructionModifier::clone() const {
    return boost::shared_ptr<InstructionModifier>(new IndirectInstructionModifier(*this));
}


boost::optional<Instruction>
IndirectInstructionModifier::findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) {
    boost::optional<Instruction> instr;
    mIndex += this->getValue();
    Instruction intermediateInstruction = memoryArray[*mIndex];
    mIndex += intermediateInstruction.getBValue();
    Instruction instrd = memoryArray[*mIndex];
    instr = instrd;
    return instr;

}
