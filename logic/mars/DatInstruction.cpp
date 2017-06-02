//
// Created by kamil on 26.04.17.
//

#include <logic/parser/CoreWarsConstants.h>
#include "DatInstruction.h"

DatInstruction::DatInstruction(const boost::shared_ptr<InstructionAddress> operatorA,
                               const boost::shared_ptr<InstructionAddress> operatorB)
        : Instruction(operatorA, operatorB) {}

DatInstruction::DatInstruction() : Instruction(ParserConstants::INSTR_CODE_DAT) {

}
