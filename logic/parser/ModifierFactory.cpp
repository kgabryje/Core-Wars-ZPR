#include <logic/mars/Instruction.h>
#include "ModifierFactory.h"
#include "ParserException.h"
#include "ImmidiateInstructionModifier.h"
#include "DirectInstructionModifier.h"

boost::shared_ptr<InstructionModifier> ModifierFactory::createModifier(const char rawModifier) {

    if (rawModifier == ParserConstants::MODIFIER_B_INDIRECT)
        return boost::shared_ptr<InstructionModifier>(new IndirectInstructionModifier());
    else if (rawModifier == ParserConstants::MODIFIER_IMMIDIATE)
        return boost::shared_ptr<InstructionModifier>(new ImmidiateInstructionModifier());
    else if (rawModifier == ParserConstants::MODIFIER_DIRECT || isModifierOmitted(rawModifier))
        return boost::shared_ptr<InstructionModifier>(new DirectInstructionModifier());
    else
        throw ParserException(ParserConstants::UKNOWN_MODIFIER_EXCEPTION + "\"" + std::string(1, rawModifier) + "\" ");

}

bool ModifierFactory::isModifierOmitted(const char modifier) {

    return isdigit(modifier) || modifier == '-';

}

boost::shared_ptr<InstructionModifier> ModifierFactory::createDefaultModifier() {
    return boost::shared_ptr<InstructionModifier>(new DirectInstructionModifier());
}
