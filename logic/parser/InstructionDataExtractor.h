#ifndef CORE_WARS_ZPR_INSTRUCTIONDATAEXTRACTOR_H
#define CORE_WARS_ZPR_INSTRUCTIONDATAEXTRACTOR_H


#include "InstructionData.h"

class InstructionDataExtractor {

public:
    InstructionData tryExtract(std::string rawInstr);
    bool isInstructionValid(std::string rawInstr);

private:
    string getRegex() const;
};


#endif //CORE_WARS_ZPR_INSTRUCTIONDATAEXTRACTOR_H
