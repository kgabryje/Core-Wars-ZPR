#ifndef CORE_WARS_ZPR_INITIALIZER_H
#define CORE_WARS_ZPR_INITIALIZER_H

#include <vector>
#include <iostream>
#include "mars/Instruction.h"

static const char *const successMessage = "success";
using namespace std;

class Initializer {

public:
    vector<Instruction> sendCodeRequestAndParse();
private:
    std::string demandCode();

    void sendParsingResult(const std::string& message);
};

#endif //CORE_WARS_ZPR_INITIALIZER_H
