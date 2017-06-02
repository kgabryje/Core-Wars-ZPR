#include "InstructionFactory.h"
#include "ParserException.h"
#include "../mars/DatInstruction.h"
#include "../mars/MovInstruction.h"
#include "CoreWarsConstants.h"

shared_ptr<Instruction> InstructionFactory::createInstruction(const string &code) {

    if (code == ParserConstants::INSTR_CODE_DAT)
        return shared_ptr<Instruction>(new DatInstruction());
    else if (code == ParserConstants::INSTR_CODE_MOV)
        return shared_ptr<Instruction>(new MovInstruction());
    else
        throw ParserException(ParserConstants::UKNOWN_CODE_EXCEPTION + code);
}
