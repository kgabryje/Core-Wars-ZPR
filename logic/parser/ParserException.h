#ifndef CORE_WARS_ZPR_PARSEREXCEPTION_H
#define CORE_WARS_ZPR_PARSEREXCEPTION_H


#include <exception>

class ParserException : public std::exception{
public:
    ParserException();

    ~ParserException() override;

    const char *what() const noexcept override;
};


#endif //CORE_WARS_ZPR_PARSEREXCEPTION_H
