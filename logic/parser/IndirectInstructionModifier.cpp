#include "IndirectInstructionModifier.h"
#include "logic/CoreWarsConstants.h"

IndirectInstructionModifier::IndirectInstructionModifier() : InstructionModifier(
        std::string(1, ParserConstants::MODIFIER_B_INDIRECT)) {}

boost::shared_ptr<InstructionModifier> IndirectInstructionModifier::clone() const {
    return boost::shared_ptr<InstructionModifier>(new IndirectInstructionModifier(*this));
}
