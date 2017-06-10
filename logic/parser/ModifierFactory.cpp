#include <logic/mars/Instruction.h>
#include "ModifierFactory.h"
#include "ParserException.h"
#include "ImmediateInstructionModifier.h"
#include "DirectInstructionModifier.h"

std::shared_ptr<InstructionModifier> ModifierFactory::createModifier(const char rawModifier) {

    if (rawModifier == ParserConstants::MODIFIER_B_INDIRECT)
        return std::shared_ptr<InstructionModifier>(new IndirectInstructionModifier());
    else if (rawModifier == ParserConstants::MODIFIER_IMMIDIATE)
        return std::shared_ptr<InstructionModifier>(new ImmediateInstructionModifier());
    else if (rawModifier == ParserConstants::MODIFIER_DIRECT || isModifierOmitted(rawModifier))
        return std::shared_ptr<InstructionModifier>(new DirectInstructionModifier());
    else
        throw ParserException(ParserConstants::UKNOWN_MODIFIER_EXCEPTION + "\"" + std::string(1, rawModifier) + "\" ");

}

bool ModifierFactory::isModifierOmitted(const char modifier) {

    return isdigit(modifier) || modifier == '-';

}

std::shared_ptr<InstructionModifier> ModifierFactory::createDefaultModifier() {
    return std::shared_ptr<InstructionModifier>(new DirectInstructionModifier());
}
