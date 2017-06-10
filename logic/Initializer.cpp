#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Initializer.h"
#include "parser/RedcodeParser.h"
#include "parser/ParserException.h"
#include "ServerConnector.h"

using namespace std;

/**
 * asks for warrior code and parses it
 * @return vector of Redcode instructions parsed from warrior code
 */
vector<Instruction> Initializer::sendCodeRequestAndParse() {
    bool codeIsFine = false;
    RedcodeParser parser;
    string message;
    vector<Instruction> instructions;

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

/**
 * Sends request for warrior code to server through ServerConnector instance
 * @return warrior code
 */
std::string Initializer::demandCode() {
    std::string code = ServerConnector::getInstance().getCode();
    return code;
}

/**
 * Sends info whether parsing code succeeded to server through ServerConnector instance
 * @param message message whether parsing succeeded
 */
void Initializer::sendParsingResult(const std::string& message) {
//tutaj wysyłanie do ServerConnector info sukces albo jest bład, poproś użytkownika o poprawiony kod
    ServerConnector::getInstance().sendMessage(message);
    cout << message << endl;
}
