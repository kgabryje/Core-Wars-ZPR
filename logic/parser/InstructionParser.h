#ifndef CORE_WARS_ZPR_INSTRUCTIONPARSER_H
#define CORE_WARS_ZPR_INSTRUCTIONPARSER_H

#include <vector>
#include <string>
#include <logic/mars/Instruction.h>
#include <c++/memory>

using namespace std;
class InstructionParser {

public:
    vector<shared_ptr<Instruction>> parseInstructions(vector<string> rawInstructions);
};


#endif //CORE_WARS_ZPR_INSTRUCTIONPARSER_H
