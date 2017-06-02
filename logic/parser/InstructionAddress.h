#ifndef CORE_WARS_ZPR_INSTRUCTIONADDRESS_H
#define CORE_WARS_ZPR_INSTRUCTIONADDRESS_H


#include "InstructionModifier.h"

class InstructionAddress {

private:
    int value;
    InstructionModifier modifier;
public:
    InstructionAddress(InstructionModifier modifier, int i);

    int getValue() const;

    void setValue(int value);

    const InstructionModifier &getModifier() const;

    void setModifier(const InstructionModifier &modifier);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONADDRESS_H
