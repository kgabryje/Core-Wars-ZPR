#include "InstructionParser.h"
#include "InstructionDataExtractor.h"
#include "ParserException.h"

vector<Instruction> InstructionParser::parseInstructions(vector<std::string> rawInstructions) {

    vector<InstructionData>metaInstructions;
    vector<Instruction> instructions;
    InstructionDataExtractor extractor;
    for (string line: rawInstructions) {
        if(!extractor.isInstructionValid(line))
            throw new ParserException();
       // InstructionData metaInstr = extractor.tryExtract(line);


    }
return instructions;



}
