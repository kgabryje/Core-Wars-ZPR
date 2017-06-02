#include "InstructionAddress.h"

InstructionAddress::InstructionAddress(InstructionModifier modifier, int i) : modifier(modifier), value(i) {

}

int InstructionAddress::getValue() const {
    return value;
}

void InstructionAddress::setValue(int value) {
    InstructionAddress::value = value;
}

const InstructionModifier &InstructionAddress::getModifier() const {
    return modifier;
}

void InstructionAddress::setModifier(const InstructionModifier &modifier) {
    InstructionAddress::modifier = modifier;
}
