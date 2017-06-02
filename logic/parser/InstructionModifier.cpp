#include "InstructionModifier.h"

const std::string &InstructionModifier::getModifierCode() const {
    return modifierCode;
}

InstructionModifier::InstructionModifier(const std::string &modifierCode) : modifierCode(modifierCode) {}
