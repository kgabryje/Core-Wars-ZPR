#include "InstructionParser.h"
#include "InstructionDataExtractor.h"
#include "ParserException.h"

vector<shared_ptr<Instruction>> InstructionParser::parseInstructions(vector<std::string> rawInstructions) {

    vector<InstructionData>metaInstructions;
    vector<shared_ptr<Instruction>> instructions;
    InstructionDataExtractor extractor;

    for (string line: rawInstructions) {
        if(!extractor.isInstructionValid(line))
            throw new ParserException();
        else {
            // InstructionData metaInstr = extractor.tryExtract(line);
        }

    }
return instructions;

}
