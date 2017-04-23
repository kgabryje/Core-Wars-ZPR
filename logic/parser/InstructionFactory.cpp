#include "InstructionFactory.h"

shared_ptr<Instruction> InstructionFactory::createInstruction(const InstructionData &data) {
    string a = data.getA_field();
    string b = data.getB_field();
    char c = a.at( a.length() - 1 );
    const InstructionOperator *aOper = new InstructionOperator("", int(a.at( a.length() - 1 ) - 48));
    const InstructionOperator *bOper = new InstructionOperator("", int(b.at( b.length() - 1 ) - 48));
    Instruction *instr = new Instruction(aOper, bOper);


    return shared_ptr<Instruction>(instr);
}
