#ifndef CORE_WARS_ZPR_ADDRESSCREATOR_H
#define CORE_WARS_ZPR_ADDRESSCREATOR_H


#include <string>
#include "InstructionAddress.h"

class AddressCreator {

public:
    static InstructionAddress *tryCreate(std::string);

    static int parseAddressValue(std::string numAsString);

    static InstructionAddress *createDefault();
};


#endif //CORE_WARS_ZPR_ADDRESSCREATOR_H
