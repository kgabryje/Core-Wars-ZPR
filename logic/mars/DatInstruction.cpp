//
// Created by kamil on 26.04.17.
//

#include <logic/parser/CoreWarsConstants.h>
#include "DatInstruction.h"

DatInstruction::DatInstruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB)
        : Instruction(operatorA, operatorB) {}

DatInstruction::DatInstruction() : Instruction(ParserConstants::INSTR_CODE_DAT) {

}
