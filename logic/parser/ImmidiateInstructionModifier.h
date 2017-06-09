#ifndef CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H

#include "InstructionModifier.h"

class ImmidiateInstructionModifier : public InstructionModifier {
public:
    ImmidiateInstructionModifier();

    boost::shared_ptr<InstructionModifier> clone() const override;

    ImmidiateInstructionModifier(const char modifierCode);

    boost::optional<Instruction>
    findTargetInstruction(MemoryIndex mIndex, const std::vector<Instruction> memoryArray) override;
};

#endif //CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H
