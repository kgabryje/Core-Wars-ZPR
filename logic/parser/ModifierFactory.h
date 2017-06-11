#ifndef CORE_WARS_ZPR_MODIFIERFACTORY_H
#define CORE_WARS_ZPR_MODIFIERFACTORY_H


#include <string>
#include "InstructionModifier.h"
#include "IndirectInstructionModifier.h"
#include <boost/shared_ptr.hpp>

/**
 * Class managing creating instruction modifiers, implementing factory design pattern
 */
class ModifierFactory {

public:
    static std::shared_ptr<InstructionModifier> createModifier(const char rawModifier);

    static bool isModifierOmitted(const char modifier);

    static std::shared_ptr<InstructionModifier> createDefaultModifier();
};


#endif //CORE_WARS_ZPR_MODIFIERFACTORY_H
