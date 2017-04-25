#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <logic/view/ViewInput.h>
#include "Initializer.h"
#include "parser/RedcodeParser.h"
#include "parser/ParserException.h"
#include "Player.h"
#include "PlayerCreator.h"
#include "Warrior.h"

using namespace std;


vector<Instruction> Initializer::sendCodeRequestAndParse() {

}

std::string Initializer::demandCode() {
    //tutaj połączenie do serwera i odbiór kodu, pewnie w klasie ServerConnector
    return "sample RedCode";
}

void Initializer::sendParsingResult(std::string message) {
//tutaj wysyłanie do ServerConnector info sukces albo jest bład,podaj kod jeszcze raz
    cout << message << endl;
}

vector<ViewInput> Initializer::obtainUserInput() {
    //std::string code = ServerConnector::getInstance().getCode();
    string przemek ("Pszemek");
    string mirek("Mirek");
    string warrior_name("warrior_name");
    string warrior_code("warrior_code");
    const ViewInput vi1(przemek,warrior_name,warrior_code);
    const ViewInput vi2(mirek,warrior_name,warrior_code);
    vector<ViewInput> inputs;
    inputs.push_back(vi1);
    inputs.push_back(vi1);
    inputs.push_back(vi2);
}

vector<Player> Initializer::initialize() {

    bool codeIsFine = false;
    RedcodeParser parser;
    string message;
    vector<Player> players;

    while (!codeIsFine) {
        vector<ViewInput> inputs = obtainUserInput();
        try {
            players = PlayerCreator::createPlayers(inputs);
            vector<Warrior> warriors = parser.parse(inputs);
            setPlayersWarriors();
            message = successMessage;
            codeIsFine = true;
        }
        catch (ParserException ex) {
            message = ex.what();
        }
        sendParsingResult(message);
    }
    return players;


}

void Initializer::setPlayersWarriors() {

}
