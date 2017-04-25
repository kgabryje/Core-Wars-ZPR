#ifndef CORE_WARS_ZPR_INITIALIZER_H
#define CORE_WARS_ZPR_INITIALIZER_H

#include <memory>
#include <vector>
#include "mars/Instruction.h"
#include "Player.h"

static const char *const successMessage = "success";
using namespace std;

class Initializer {

public:
    vector<Instruction>  sendCodeRequestAndParse();

    vector<ViewInput>obtainUserInput();

    vector<Player> initialize();

private:
    std::string demandCode();

    void sendParsingResult(std::string basic_string);

    void setPlayersWarriors();
};

#endif //CORE_WARS_ZPR_INITIALIZER_H
