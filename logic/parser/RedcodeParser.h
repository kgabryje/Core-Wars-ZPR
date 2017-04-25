#ifndef CORE_WARS_ZPR_REDCODEPARSER_H
#define CORE_WARS_ZPR_REDCODEPARSER_H


#include "InstructionData.h"
#include "../mars/Instruction.h"

class RedcodeParser {
public:
    std::vector<Warrior> parse(vector<ViewInput>);

private:
    vector<InstructionData> preprocessCode(const ViewInput &input);
};


#endif //CORE_WARS_ZPR_REDCODEPARSER_H
