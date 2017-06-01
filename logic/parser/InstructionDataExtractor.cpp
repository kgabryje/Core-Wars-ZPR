#include <boost/regex.hpp>
#include "InstructionDataExtractor.h"

InstructionData InstructionDataExtractor::tryExtract(std::string rawInstr) {
    return InstructionData("","","");
}

bool InstructionDataExtractor::isInstructionValid(std::string rawInstr) {

    static const boost::regex e(getRegex());
    return (boost::regex_match(rawInstr, e));

}
//boost::match_results<std::string::const_iterator> results;
//return (boost::regex_match(rawInstr, results, e));
//bool RedcodeParser::testMe(string input) {
//
//    static const boost::regex e(getRegex());
//    boost::match_results<std::string::const_iterator> results;
//    if (boost::regex_match(input, results, e)) {
////        std::cout << results[0] << "\n";
////        std::cout << results[1] << "\n";
////        std::cout << results[2] << "\n";
////        std::cout << results[3] << "\n";
////        std::cout << results[4] << "\n";
//        std::string playername = results[2];  //Get contents of the second (...)
//    }
//
//    return (boost::regex_match(input, results, e));
//}

string InstructionDataExtractor::getRegex() const {
    return "^\\s*([A-Z]{3})\\s+([@$#]?-?\\d+)(?:\\s*,\\s*([@$#]?-?\\d+))?\\s*(?:;.*)?";
}