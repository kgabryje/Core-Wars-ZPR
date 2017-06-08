#ifndef CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H

#include <string>

class InstructionModifier {
public:
    InstructionModifier(const std::string &modifierCode, int value = 0);

    const std::string &getModifierCode() const;

    int getValue() const;

    void setValue(int value);

    void setModifierCode(const std::string &modifierCode);

private:
    int value;
    std::string modifierCode;
};


#endif //CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H
