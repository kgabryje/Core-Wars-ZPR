#include "InstructionData.h"

InstructionData::InstructionData(const string &code, const string &a_field, const string &b_field) : opCode(code),
                                                                                      aField(a_field),
                                                                                      bField(b_field) {}

const string &InstructionData::getCode() const {
    return opCode;
}

void InstructionData::setCode(const string &code) {
    InstructionData::opCode = code;
}

const string &InstructionData::getA_field() const {
    return aField;
}

void InstructionData::setA_field(const string &a_field) {
    InstructionData::aField = a_field;
}

const string &InstructionData::getB_field() const {
    return bField;
}

void InstructionData::setB_field(const string &b_field) {
    InstructionData::bField = b_field;
}
