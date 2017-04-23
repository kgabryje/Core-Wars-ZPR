#ifndef CORE_WARS_ZPR_INITIALIZER_H
#define CORE_WARS_ZPR_INITIALIZER_H

#include <memory>
#include <vector>
#include "mars/Instruction.h"

static const char *const successMessage = "success";
using namespace std;

class Initializer {

public:
    vector<shared_ptr<Instruction>>  sendCodeRequestAndParse();
private:
    std::string demandCode();

    void sendParsingResult(std::string basic_string);
};

#endif //CORE_WARS_ZPR_INITIALIZER_H
