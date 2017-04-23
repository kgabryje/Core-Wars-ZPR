#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Initializer.h"
#include "parser/RedcodeParser.h"
#include "parser/ParserException.h"

using namespace std;


vector<shared_ptr<Instruction>> Initializer::sendCodeRequestAndParse() {
    bool codeIsFine = false;
    RedcodeParser parser;
    string message;
    vector<shared_ptr<Instruction>> instructions;

    while (!codeIsFine) {
        string code = demandCode();
        try {
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
    //tutaj połączenie do serwera i odbiór kodu, pewnie w klasie ServerConnector
    return "sample RedCode";
}

void Initializer::sendParsingResult(std::string message) {
//tutaj wysyłanie do ServerConnector info sukces albo jest bład,podaj kod jeszcze raz
    cout<<message<<endl;
}
