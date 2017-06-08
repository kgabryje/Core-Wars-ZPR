#ifndef CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H

#include "InstructionModifier.h"

class ImmidiateInstructionModifier : public InstructionModifier {
public:
    ImmidiateInstructionModifier();

    boost::shared_ptr<InstructionModifier> clone() const override;

    ImmidiateInstructionModifier(const char modifierCode);
};

#endif //CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H
