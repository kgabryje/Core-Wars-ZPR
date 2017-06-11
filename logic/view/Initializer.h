#ifndef CORE_WARS_ZPR_INITIALIZER_H
#define CORE_WARS_ZPR_INITIALIZER_H

#include <vector>
#include <iostream>
#include "logic/mars/Instruction.h"
#include "gen-cpp/mars_types.h"
#include "PlayerData.h"

using namespace std;

class Initializer {

public:
    PlayerData sendCodeRequestAndParse(string successMessage);
private:
    MARS::Code demandCode();

    void sendParsingResult(const std::string& message);
};

#endif //CORE_WARS_ZPR_INITIALIZER_H
