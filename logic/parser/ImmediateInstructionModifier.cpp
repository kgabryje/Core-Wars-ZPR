#include "ImmediateInstructionModifier.h"
#include "logic/CoreWarsConstants.h"

ImmediateInstructionModifier::ImmediateInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_IMMIDIATE)) {
}

InstructionModifier *ImmediateInstructionModifier::clone() const {
    return new ImmediateInstructionModifier(*this);
}

boost::optional<Instruction>
ImmediateInstructionModifier::findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) {
    boost::optional<Instruction> instr;
    return instr;
}
