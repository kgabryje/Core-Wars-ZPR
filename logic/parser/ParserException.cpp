#include "ParserException.h"


const char *ParserException::what() const noexcept {
    return "Problem has occurred during parsing";
}


ParserException::ParserException() : exception() {

}

ParserException::~ParserException() {

}

