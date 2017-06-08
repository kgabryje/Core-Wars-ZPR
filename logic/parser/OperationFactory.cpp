#include "OperationFactory.h"
#include "ParserException.h"
#include "logic/CoreWarsConstants.h"
#include "logic/mars/DatOperation.h"
#include "logic/mars/MovOperation.h"

boost::shared_ptr<Operation> OperationFactory::createOperation(const string &code) {

    if (code == ParserConstants::INSTR_CODE_DAT)
        return boost::shared_ptr<Operation>(new DatOperation());
    else if (code == ParserConstants::INSTR_CODE_MOV)
        return boost::shared_ptr<Operation>(new MovOperation());
    else
        throw ParserException(ParserConstants::UKNOWN_CODE_EXCEPTION + code);
}
