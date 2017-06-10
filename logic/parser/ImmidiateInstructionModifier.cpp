#include "ImmidiateInstructionModifier.h"
#include "logic/CoreWarsConstants.h"

ImmidiateInstructionModifier::ImmidiateInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_IMMIDIATE)) {
}

boost::shared_ptr<InstructionModifier> ImmidiateInstructionModifier::clone() const {
    return boost::shared_ptr<InstructionModifier>(new ImmidiateInstructionModifier(*this));
}

boost::optional<Instruction>
ImmidiateInstructionModifier::findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) {
    boost::optional<Instruction> instr;
    return instr;
}
