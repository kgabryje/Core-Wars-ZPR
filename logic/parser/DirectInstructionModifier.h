#ifndef CORE_WARS_ZPR_DIRECTINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_DIRECTINSTRUCTIONMODIFIER_H


#include "InstructionModifier.h"

class DirectInstructionModifier : public InstructionModifier {
public:
    DirectInstructionModifier();

    boost::optional<Instruction>
    findTargetInstruction(MemoryIndex &mIndex, const std::vector<Instruction> memoryArray) override;

    boost::shared_ptr<InstructionModifier> clone() const override;
};


#endif //CORE_WARS_ZPR_DIRECTINSTRUCTIONMODIFIER_H
