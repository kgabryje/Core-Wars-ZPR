#include "InstructionModifier.h"

const std::string &InstructionModifier::getModifierCode() const {
    return modifierCode;
}

InstructionModifier::InstructionModifier(const std::string &modifierCode, int value) : modifierCode(modifierCode),
                                                                                       value(value) {}

int InstructionModifier::getValue() const {
    return value;
}

void InstructionModifier::setValue(int value) {
    InstructionModifier::value = value;
}

void InstructionModifier::setModifierCode(const std::string &modifierCode) {
    InstructionModifier::modifierCode = modifierCode;
}


