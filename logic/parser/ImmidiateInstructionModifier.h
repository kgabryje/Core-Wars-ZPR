#ifndef CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H

#include "InstructionModifier.h"

class ImmidiateInstructionModifier : public InstructionModifier {
public:
    ImmidiateInstructionModifier();

    ImmidiateInstructionModifier(const char modifierCode);
};

#endif //CORE_WARS_ZPR_IMMIDIATEINSTRUCTIONMODIFIER_H
