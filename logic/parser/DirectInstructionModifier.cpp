#include "DirectInstructionModifier.h"


DirectInstructionModifier::DirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_DIRECT)) {
}

boost::shared_ptr<InstructionModifier> DirectInstructionModifier::clone() const {
    return boost::shared_ptr<InstructionModifier>(new DirectInstructionModifier(*this));
}

boost::optional<Instruction>
DirectInstructionModifier::findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) {
    boost::optional<Instruction> instr;
    mIndex += this->getValue();
    Instruction intermediateInstruction = memoryArray[*mIndex];
    //mIndex += intermediateInstruction.getBValue();
    //instr = memoryArray[*mIndex];

    // return instr;
    return intermediateInstruction;
}
