#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <boost/lexical_cast.hpp>
#include "AddressCreator.h"
#include "ModifierFactory.h"
#include "ParserException.h"
#include "CoreWarsConstants.h"

InstructionAddress AddressCreator::tryCreate(std::string rawAddress) {

    char rawModifier = rawAddress[0];
    InstructionModifier modifier = ModifierFactory::createModifier(rawModifier);
    int addressValue = parseFromString(rawAddress);
    return InstructionAddress(modifier, addressValue);
}

int AddressCreator::parseFromString(std::string numAsString) {
    int value;
    try {
        value = boost::lexical_cast<int>(numAsString);
    }
    catch (boost::bad_lexical_cast &e) {
        try {
            value = boost::lexical_cast<int>(numAsString.substr(1));
        }
        catch (boost::bad_lexical_cast &e) {

            throw ParserException(ParserConstants::WRONG_NUMBER_EXCEPTION);
        }
    }
    return value;
}
