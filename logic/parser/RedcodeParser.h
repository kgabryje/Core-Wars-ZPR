#ifndef CORE_WARS_ZPR_REDCODEPARSER_H
#define CORE_WARS_ZPR_REDCODEPARSER_H

#include "InstructionData.h"
#include "../mars/Instruction.h"

class RedcodeParser {
public:
    static std::vector<Instruction> parse(string fileContents);
    vector<InstructionData> preprocessCode(const string& data);
private:


    string getRegex() const;
};


#endif //CORE_WARS_ZPR_REDCODEPARSER_H
