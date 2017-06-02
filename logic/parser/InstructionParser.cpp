#include <iostream>
#include "InstructionParser.h"
#include "InstructionDataExtractor.h"
#include "ParserException.h"
#include "CoreWarsConstants.h"
#include "InstructionCreator.h"

vector<shared_ptr<Instruction>> InstructionParser::parseInstructions(vector<std::string> rawInstructions) {

    vector<InstructionData> metaInstructions;
    vector<shared_ptr<Instruction>> instructions;
    InstructionDataExtractor extractor;

    for (string line: rawInstructions) {
        if (!extractor.isInstructionValid(line))
            throw ParserException(ParserConstants::WRONG_SYNTAX_EXCEPTION);
        else {
            InstructionData metaInstr = extractor.tryExtract(line);
            InstructionCreator creator;
            Instruction intstr = creator.tryCreate(metaInstr);
        }

    }
    return instructions;

}
