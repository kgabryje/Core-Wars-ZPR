#ifndef CORE_WARS_ZPR_ADDRESSCREATOR_H
#define CORE_WARS_ZPR_ADDRESSCREATOR_H


#include <string>
#include "InstructionModifier.h"
#include <boost/shared_ptr.hpp>


class InstructionModifierCreator {

public:
    static std::shared_ptr<InstructionModifier> tryCreate(std::string);

    static int parseAddressValue(std::string numAsString);

    static std::shared_ptr<InstructionModifier> createDefault();
};


#endif //CORE_WARS_ZPR_ADDRESSCREATOR_H
