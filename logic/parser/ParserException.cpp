#include "ParserException.h"

ParserException::ParserException(const std::string &msg) : message(msg) {}


const char *ParserException::what() const noexcept {
    return message.c_str();
}

ParserException::~ParserException() {

}
