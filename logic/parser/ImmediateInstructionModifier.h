#ifndef CORE_WARS_ZPR_IMMEDIATEINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_IMMEDIATEINSTRUCTIONMODIFIER_H

#include "InstructionModifier.h"

class ImmediateInstructionModifier : public InstructionModifier {
public:
    ImmediateInstructionModifier();

    std::shared_ptr<InstructionModifier> clone() const override;

    ImmediateInstructionModifier(const char modifierCode);

    boost::optional<Instruction>
    findTargetInstruction(MemoryIndex mIndex, const std::vector<Instruction> memoryArray) override;
};

#endif //CORE_WARS_ZPR_IMMEDIATEINSTRUCTIONMODIFIER_H
