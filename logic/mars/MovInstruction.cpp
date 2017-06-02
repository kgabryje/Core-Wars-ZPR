//
// Created by kamil on 26.04.17.
//
#include "MovInstruction.h"

MovInstruction::MovInstruction(const InstructionOperator *operatorA, const InstructionOperator *operatorB)
        : Instruction(operatorA, operatorB) {}

MovInstruction::MovInstruction() : Instruction(ParserConstants::INSTR_CODE_MOV) {

}
