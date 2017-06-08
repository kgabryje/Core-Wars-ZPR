#include <logic/mars/Instruction.h>
#include "ModifierFactory.h"
#include "ParserException.h"
#include "ImmidiateInstructionModifier.h"
#include "DirectInstructionModifier.h"

InstructionModifier *ModifierFactory::createModifier(const char rawModifier) {

    if (rawModifier == ParserConstants::MODIFIER_B_INDIRECT)
        return new IndirectInstructionModifier();
    else if (rawModifier == ParserConstants::MODIFIER_IMMIDIATE)
        return new ImmidiateInstructionModifier();
    else if (rawModifier == ParserConstants::MODIFIER_DIRECT || isModifierOmitted(rawModifier))
        return new DirectInstructionModifier();
    else
        throw ParserException(ParserConstants::UKNOWN_MODIFIER_EXCEPTION + "\"" + std::string(1, rawModifier) + "\" ");

}

bool ModifierFactory::isModifierOmitted(const char modifier) {

    return isdigit(modifier) || modifier == '-';

}

InstructionModifier ModifierFactory::createDefaultModifier() {
    return DirectInstructionModifier();
}
