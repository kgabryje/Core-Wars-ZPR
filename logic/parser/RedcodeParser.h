#ifndef CORE_WARS_ZPR_REDCODEPARSER_H
#define CORE_WARS_ZPR_REDCODEPARSER_H


#include <memory>
#include "InstructionData.h"
#include "../mars/Instruction.h"

class RedcodeParser {
public:
    std::vector<std::shared_ptr<Instruction>> parse(string fileContents);

private:
    vector<InstructionData> preprocessCode();
};


#endif //CORE_WARS_ZPR_REDCODEPARSER_H
