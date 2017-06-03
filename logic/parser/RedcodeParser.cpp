#include <vector>
#include "RedcodeParser.h"
#include "RawCodeFormatter.h"
#include "InstructionParser.h"


vector<shared_ptr<Instruction>> RedcodeParser::parse(string fileContents) {

    RawCodeFormatter formatter;
    std::vector<std::pair<int, std::string>> codeLines = formatter.format(fileContents);

    InstructionParser instructionParser;
    vector<shared_ptr<Instruction>> instructions = instructionParser.parseInstructions(codeLines);

    return instructions;
}