#ifndef CORE_WARS_ZPR_PARSEREXCEPTION_H
#define CORE_WARS_ZPR_PARSEREXCEPTION_H

#include <string>

/**
 * Parser exception class
 */
class ParserException : public std::exception{
public:
    ParserException(const std::string &message);

    ~ParserException() override;

    const char *what() const noexcept override;

protected:
    std::string message;
};


#endif //CORE_WARS_ZPR_PARSEREXCEPTION_H
