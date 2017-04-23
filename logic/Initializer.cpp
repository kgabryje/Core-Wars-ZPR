#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Initializer.h"
#include "parser/RedcodeParser.h"
#include "parser/ParserException.h"
#include "ServerConnector.h"

using namespace std;


vector<shared_ptr<Instruction>> Initializer::sendCodeRequestAndParse() {
    bool codeIsFine = false;
    RedcodeParser parser;
    string message;
    vector<shared_ptr<Instruction>> instructions;

    while (!codeIsFine) {
        string code = demandCode();
        try {
            std::cout << "Received instructions: " << code << std::endl;
            instructions = parser.parse(code);
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

std::string Initializer::demandCode() {
    std::string code = ServerConnector::getInstance().getCode();
    return code;
}

void Initializer::sendParsingResult(std::string message) {
//tutaj wysyłanie do ServerConnector info sukces albo jest bład,podaj kod jeszcze raz
    cout << message << endl;
}
