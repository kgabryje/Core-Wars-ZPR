#include <iostream>
#include "InstructionParser.h"
#include "InstructionDataExtractor.h"
#include "ParserException.h"
#include "InstructionCreator.h"

vector<shared_ptr<Instruction>>
InstructionParser::parseInstructions(std::vector<std::pair<int, std::string>> rawInstructions) {

    vector<shared_ptr<Instruction>> instructions;
    InstructionDataExtractor extractor;

    for (pair<int, string> line: rawInstructions) {
        if (!extractor.isInstructionValid(line.second))
            throw ParserException(
                    ParserConstants::WRONG_SYNTAX_EXCEPTION + "(line: " + std::to_string(line.first) + ")");
        else {
            try {
                InstructionData metaInstr = extractor.tryExtract(line.second);
                shared_ptr<Instruction> intstr = InstructionCreator::tryCreate(metaInstr);
                instructions.push_back(intstr);
            }
            catch (ParserException &pe) {
                throw ParserException(std::string(pe.what()) + " (line: " + std::to_string(line.first) + ")");
            }

        }

    }
    return instructions;

}
