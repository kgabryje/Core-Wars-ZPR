#include "InstructionParser.h"
#include "InstructionDataExtractor.h"
#include "ParserException.h"
#include "InstructionCreator.h"

vector<shared_ptr<Instruction>>
InstructionParser::parseInstructions(std::vector<std::pair<int, std::string>> rawInstructions) {

    vector<shared_ptr<Instruction>> instructions;
    for (pair<int, string> line: rawInstructions) {
        try {
            instructions.push_back(parseInstruction(line.second));
        }
        catch (ParserException &pe) {
            throw ParserException(std::string(pe.what()) + "(line: " + std::to_string(line.first) + ")");

        }
    }
    return instructions;
}

shared_ptr<Instruction> InstructionParser::parseInstruction(string line) {

    InstructionDataExtractor extractor;
    if (!extractor.isInstructionValid(line))
        throw ParserException(ParserConstants::WRONG_SYNTAX_EXCEPTION);
    else {
        InstructionData metaInstr = extractor.tryExtract(line);
        return InstructionCreator::tryCreate(metaInstr);
    }
}