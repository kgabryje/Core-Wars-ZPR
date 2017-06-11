#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Initializer.h"
#include "logic/parser/RedcodeParser.h"
#include "logic/parser/ParserException.h"
#include "logic/ServerConnector.h"
#include "PlayerData.h"

using namespace std;


PlayerData Initializer::sendCodeRequestAndParse(string successMessage) {
    bool codeIsFine = false;
    RedcodeParser parser;
    string message;
    vector<Instruction> instructions;
    MARS::Code code;
    while (!codeIsFine) {
        code = demandCode();
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
    PlayerData player;
    player.setInstructions(instructions);
    player.setName(code.playerName);
    player.setWarriorName(code.warriorName);

    return player;
}

MARS::Code Initializer::demandCode() {
    MARS::Code code = ServerConnector::getInstance().getCode();
    return code;
}

void Initializer::sendParsingResult(const std::string& message) {
    ServerConnector::getInstance().sendMessage(message);
}
