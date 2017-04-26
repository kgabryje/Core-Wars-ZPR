#include <vector>
#include "RedcodeParser.h"

#include "InstructionFactory.h"
#include "ParserException.h"


vector<shared_ptr<Instruction>> RedcodeParser::parse(string fileContents) {
    vector<InstructionData> metaInstructions = preprocessCode(fileContents);
    vector<shared_ptr<Instruction>> redCodeInstructions;

    for (const InstructionData &instr : metaInstructions) {
//        if(instr.getCode() == "code: 7")
//            throw ParserException();
        redCodeInstructions.push_back(InstructionFactory::createInstruction(instr));
    }

    return redCodeInstructions;
}

vector<InstructionData> RedcodeParser::preprocessCode(const string& data) {
    vector<InstructionData> metaInstructions;
    int i = 6;
    while (--i > 0) {
        const string code = data;
        const string fieldA = "fieldA: " + to_string(i);
        const string fieldB = "fieldB: " + to_string(i);

        metaInstructions.push_back(InstructionData(code, fieldA, fieldB));
    }
    return metaInstructions;
}
