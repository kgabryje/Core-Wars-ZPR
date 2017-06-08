#include "DirectInstructionModifier.h"
#include "InstructionModifier.h"
#include "logic/CoreWarsConstants.h"


DirectInstructionModifier::DirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_DIRECT)) {
}

boost::shared_ptr<InstructionModifier> DirectInstructionModifier::clone() const {
    return boost::shared_ptr<InstructionModifier>(new DirectInstructionModifier(*this));
}
