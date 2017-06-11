#include <vector>
#include "RedcodeParser.h"
#include "RawCodeFormatter.h"
#include "InstructionParser.h"

/**
 * Parses formatted lines of code into instructions
 * @param fileContents warrior code
 * @return vector of instructions
 */
vector<Instruction> RedcodeParser::parse(string fileContents) {

    RawCodeFormatter formatter;
    std::vector<std::pair<int, std::string>> codeLines = formatter.format(fileContents);

    InstructionParser instructionParser;
    vector<Instruction> instructions = instructionParser.parseInstructions(codeLines);

    return instructions;
}