#ifndef CORE_WARS_ZPR_ADDRESSCREATOR_H
#define CORE_WARS_ZPR_ADDRESSCREATOR_H


#include <string>
#include "InstructionAddress.h"

class AddressCreator {

public:
    static InstructionAddress *tryCreate(std::string);

    static int parseFromString(std::string numAsString);
};


#endif //CORE_WARS_ZPR_ADDRESSCREATOR_H
