#include "IndirectInstructionModifier.h"
#include "logic/CoreWarsConstants.h"

IndirectInstructionModifier::IndirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_B_INDIRECT)) {}
