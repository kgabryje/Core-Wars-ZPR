#include <regex>
#include "InstructionDataExtractor.h"
#include "ParserException.h"
#include "logic/CoreWarsConstants.h"

bool InstructionDataExtractor::isInstructionValid(std::string rawInstr) {

    static const std::regex e(getRegex());
    return (std::regex_match(rawInstr, e));

}

InstructionData InstructionDataExtractor::tryExtract(std::string rawInstr) {

    std::match_results<std::string::const_iterator> results;

    static const std::regex e(getRegex());
    if (!std::regex_match(rawInstr, results, e))
        throw ParserException(ParserConstants::WRONG_SYNTAX_EXCEPTION);

    return InstructionData(results[1], results[2], results[3]);
}

string InstructionDataExtractor::getRegex() const {
    return "^\\s*([A-Z]{3})\\s+(.?-?\\d+)(?:\\s*,\\s*(.?-?\\d+))?\\s*(?:;.*)?";
}