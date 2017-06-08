#include "InstructionParser.h"
#include "InstructionDataExtractor.h"
#include "ParserException.h"
#include "InstructionCreator.h"

vector<Instruction> InstructionParser::parseInstructions(std::vector<std::pair<int, std::string>> rawInstructions) {

    vector<Instruction> instructions;
    for (pair<int, std::string> line: rawInstructions) {
        try {
            instructions.push_back(parseInstruction(line.second));
        }
        catch (ParserException &pe) {
            throw ParserException(std::string(pe.what()) + "(line: " + std::to_string(line.first) + ")");

        }
    }
    return instructions;
}

Instruction InstructionParser::parseInstruction(string line) {

    InstructionDataExtractor extractor;
    if (!extractor.isInstructionValid(line))
        throw ParserException(ParserConstants::WRONG_SYNTAX_EXCEPTION);
    else {
        InstructionData metaInstr = extractor.tryExtract(line);
        return InstructionCreator::tryCreate(metaInstr);
    }
}