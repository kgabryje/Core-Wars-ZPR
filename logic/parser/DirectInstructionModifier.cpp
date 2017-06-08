#include "DirectInstructionModifier.h"
#include "InstructionModifier.h"
#include "logic/CoreWarsConstants.h"


DirectInstructionModifier::DirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_DIRECT)) {
}
