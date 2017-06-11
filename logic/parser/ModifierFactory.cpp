#include <logic/mars/Instruction.h>
#include "ModifierFactory.h"
#include "ParserException.h"
#include "ImmediateInstructionModifier.h"
#include "DirectInstructionModifier.h"

/**
 * Creates instruction modfiers
 * @param rawModifier Instruction modifier code
 * @return InstructionModifier object of class deduced from code
 */
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

/**
 *
 * @param modifier
 * @return true if modifier equals "-" or is digit
 */
bool ModifierFactory::isModifierOmitted(const char modifier) {

    return isdigit(modifier) || modifier == '-';

}

/**
 * Creates shared pointer to object initialized with default constructor
 * @return pointer to DirectInstructionModifier
 */
std::shared_ptr<InstructionModifier> ModifierFactory::createDefaultModifier() {
    return std::shared_ptr<InstructionModifier>(new DirectInstructionModifier());
}
