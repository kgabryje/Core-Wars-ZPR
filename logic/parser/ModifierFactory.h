#ifndef CORE_WARS_ZPR_MODIFIERFACTORY_H
#define CORE_WARS_ZPR_MODIFIERFACTORY_H


#include <string>
#include "InstructionModifier.h"

class ModifierFactory {

public:
    static InstructionModifier createModifier(const char rawModifier);

    static bool isModifierOmitted(const char modifier);

    static InstructionModifier createDefaultModifier();
};


#endif //CORE_WARS_ZPR_MODIFIERFACTORY_H
