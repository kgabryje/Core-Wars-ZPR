#include <vector>
#include <logic/view/ViewInput.h>
#include <logic/Warrior.h>
#include "RedcodeParser.h"

#include "InstructionFactory.h"
#include "ParserException.h"


vector<Warrior> RedcodeParser::parse(vector<ViewInput> inputs) {
    vector<Warrior> warriors;
    for (ViewInput &input : inputs) {
        vector<InstructionData> metaInstructions = preprocessCode(input);
        vector<Instruction> redCodeInstructions;

        for (const InstructionData &instr : metaInstructions) {
            if (instr.getCode() == "code: 5")
                throw ParserException();
            redCodeInstructions.push_back(InstructionFactory::createInstruction(instr));
        }
        Warrior warrior(input.getWarriorName(),redCodeInstructions);
        warriors.push_back(warrior);
    }

    return warriors;
}

vector<InstructionData> RedcodeParser::preprocessCode(const ViewInput &input) {
    vector<InstructionData> metaInstructions;
    int i = 5;
    while (--i > 0) {
        const string code = "code: " + to_string(i);
        const string fieldA = "fieldA: " + to_string(i);
        const string fieldB = "fieldB: " + to_string(i);

        metaInstructions.push_back(InstructionData(code, fieldA, fieldB));
    }
    return metaInstructions;
}
