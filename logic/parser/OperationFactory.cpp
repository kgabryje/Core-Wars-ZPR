#include <logic/mars/AddOperation.h>
#include <logic/mars/JmpOperation.h>
#include "OperationFactory.h"
#include "ParserException.h"
#include "logic/mars/DatOperation.h"
#include "logic/mars/MovOperation.h"

boost::shared_ptr<MarsOperation> OperationFactory::createOperation(const string &code) {

    if (code == ParserConstants::INSTR_CODE_DAT)
        return boost::shared_ptr<MarsOperation>(new DatOperation());
    else if (code == ParserConstants::INSTR_CODE_MOV)
        return boost::shared_ptr<MarsOperation>(new MovOperation());
    else if (code == ParserConstants::INSTR_CODE_ADD)
        return boost::shared_ptr<MarsOperation>(new AddOperation());
    else if (code == ParserConstants::INSTR_CODE_JMP)
        return boost::shared_ptr<MarsOperation>(new JmpOperation());
    else
        throw ParserException(ParserConstants::UKNOWN_CODE_EXCEPTION + code);
}
