#ifndef CORE_WARS_ZPR_DIRECTINSTRUCTIONMODIFIER_H
#define CORE_WARS_ZPR_DIRECTINSTRUCTIONMODIFIER_H


#include "InstructionModifier.h"

class DirectInstructionModifier : public InstructionModifier {
public:
    DirectInstructionModifier();

    boost::shared_ptr<InstructionModifier> clone() const override;
};


#endif //CORE_WARS_ZPR_DIRECTINSTRUCTIONMODIFIER_H
