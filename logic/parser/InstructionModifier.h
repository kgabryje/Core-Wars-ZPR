#ifndef CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H

#include <string>

class InstructionModifier {
public:
    InstructionModifier(const std::string &modifierCode);

public:
    const std::string &getModifierCode() const;

private:
    std::string modifierCode;
};


#endif //CORE_WARS_ZPR_INSTRUCTIONMODIFIER_H
