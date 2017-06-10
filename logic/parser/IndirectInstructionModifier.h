#ifndef CORE_WARS_ZPR_INDIRECTINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_INDIRECTINSTRUCTIONMODIFIER_H


#include "InstructionModifier.h"

class IndirectInstructionModifier : public InstructionModifier {
public:
    IndirectInstructionModifier();

    boost::shared_ptr<InstructionModifier> clone() const override;

    boost::optional<Instruction>
    findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) override;
};


#endif //CORE_WARS_ZPR_INDIRECTINSTRUCTIONMODIFIER_H
