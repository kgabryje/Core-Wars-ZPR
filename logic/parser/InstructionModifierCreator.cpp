#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include <boost/lexical_cast.hpp>
#include "InstructionModifierCreator.h"
#include "ModifierFactory.h"
#include "ParserException.h"
#include "logic/CoreWarsConstants.h"
#include <logic/mars/Instruction.h>

std::shared_ptr<InstructionModifier> InstructionModifierCreator::tryCreate(std::string rawAddress) {

    char rawModifier = rawAddress[0];
    std::shared_ptr<InstructionModifier> mod = ModifierFactory::createModifier(rawModifier);
    int addressValue = parseAddressValue(rawAddress);
    mod.get()->setValue(addressValue);

    return mod;

}

int InstructionModifierCreator::parseAddressValue(std::string numAsString) {
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

std::shared_ptr<InstructionModifier> InstructionModifierCreator::createDefault() {
    return ModifierFactory::createDefaultModifier();


}
