//
// Created by kamil on 26.04.17.
//
#include "MovInstruction.h"

MovInstruction::MovInstruction(const boost::shared_ptr<InstructionAddress> operatorA,
                               const boost::shared_ptr<InstructionAddress> operatorB)
        : Instruction(operatorA, operatorB) {}

MovInstruction::MovInstruction() : Instruction(ParserConstants::INSTR_CODE_MOV) {

}
