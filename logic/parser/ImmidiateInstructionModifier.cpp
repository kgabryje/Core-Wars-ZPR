#include "ImmidiateInstructionModifier.h"
#include "CoreWarsConstants.h"

ImmidiateInstructionModifier::ImmidiateInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_IMMIDIATE)) {
}
