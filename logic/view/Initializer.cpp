#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "logic/Initializer.h"
#include "logic/parser/RedcodeParser.h"
#include "logic/parser/ParserException.h"
#include "logic/ServerConnector.h"

using namespace std;


vector<Instruction> Initializer::sendCodeRequestAndParse(string successMessage) {
    bool codeIsFine = false;
    RedcodeParser parser;
    string message;
    vector<Instruction> instructions;

    while (!codeIsFine) {
        MARS::Code code = demandCode();
        try {
            instructions = parser.parse(code.code);
            message = successMessage;
            codeIsFine = true;
        }
        catch (ParserException ex) {
            message = ex.what();
        }
        sendParsingResult(message);
    }
    return instructions;
}

MARS::Code Initializer::demandCode() {
    MARS::Code code = ServerConnector::getInstance().getCode();
    return code;
}

void Initializer::sendParsingResult(const std::string& message) {
    ServerConnector::getInstance().sendMessage(message);
}
