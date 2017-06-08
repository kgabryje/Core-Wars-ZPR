#ifndef CORE_WARS_ZPR_OPERATION_H
#define CORE_WARS_ZPR_OPERATION_H

#include <string>

class Operation {
public:
    Operation(const std::string opCode);

    Operation();

    const std::string &getOpCode() const;

private:
    const std::string opCode;
};


#endif //CORE_WARS_ZPR_OPERATION_H
