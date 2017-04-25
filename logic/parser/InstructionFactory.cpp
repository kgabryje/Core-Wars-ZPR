#include "InstructionFactory.h"

Instruction InstructionFactory::createInstruction(const InstructionData &data) {
    string a = data.getA_field();
    string b = data.getB_field();
    const InstructionOperator aOper("", int(a.at( a.length() - 1 ) - 48));
    const InstructionOperator bOper("", int(b.at( b.length() - 1 ) - 48));
    return Instruction(aOper, bOper);

}
