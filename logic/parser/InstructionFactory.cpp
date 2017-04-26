#include "InstructionFactory.h"
#include "ParserException.h"
#include "../mars/DatInstruction.h"
#include "../mars/MovInstruction.h"

shared_ptr<Instruction> InstructionFactory::createInstruction(const InstructionData &data) {
    string a = data.getA_field();
    string b = data.getB_field();
    const InstructionOperator *aOper = new InstructionOperator("", int(a.at( a.length() - 1 ) - 48));
    const InstructionOperator *bOper = new InstructionOperator("", int(b.at( b.length() - 1 ) - 48));
    Instruction *instr = new Instruction(aOper, bOper);
    string dataCode =  data.getCode();
    if(dataCode == "DAT")
        return shared_ptr<Instruction>(new DatInstruction(aOper, bOper));
    else if(dataCode == "MOV")
        return shared_ptr<Instruction>(new MovInstruction(aOper, bOper));
    else
        throw ParserException();
}
