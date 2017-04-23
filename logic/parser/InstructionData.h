#ifndef CORE_WARS_ZPR_INSTRUCTIONDATA_H
#define CORE_WARS_ZPR_INSTRUCTIONDATA_H

#include <string>

using namespace std;

class InstructionData {
public:
    InstructionData(const string &code, const string &a_field, const string &b_field);

    const string &getCode() const;

    void setCode(const string &code);

    const string &getA_field() const;

    void setA_field(const string &a_field);

    const string &getB_field() const;

    void setB_field(const string &b_field);

private:
    string opCode;
    string aField;
    string bField;
};


#endif //CORE_WARS_ZPR_INSTRUCTIONDATA_H
