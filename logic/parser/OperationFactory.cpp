#include <logic/mars/AddOperation.h>
#include <logic/mars/JmpOperation.h>
#include "OperationFactory.h"
#include "ParserException.h"
#include "logic/mars/DatOperation.h"
#include "logic/mars/MovOperation.h"

/**
 * Creates operations
 * @param code Instruction code
 * @return MarsOperation object of class deduced from code
 */
std::shared_ptr<MarsOperation> OperationFactory::createOperation(const string &code) {

    if (code == ParserConstants::INSTR_CODE_DAT)
        return std::shared_ptr<MarsOperation>(new DatOperation());
    else if (code == ParserConstants::INSTR_CODE_MOV)
        return std::shared_ptr<MarsOperation>(new MovOperation());
    else if (code == ParserConstants::INSTR_CODE_ADD)
        return std::shared_ptr<MarsOperation>(new AddOperation());
    else if (code == ParserConstants::INSTR_CODE_JMP)
        return std::shared_ptr<MarsOperation>(new JmpOperation());
    else
        throw ParserException(ParserConstants::UKNOWN_CODE_EXCEPTION + code);
}
