/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "mars_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace MARS {


Code::~Code() throw() {
}


void Code::__set_code(const std::string& val) {
  this->code = val;
}

uint32_t Code::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->code);
          this->__isset.code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Code::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Code");

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Code &a, Code &b) {
  using ::std::swap;
  swap(a.code, b.code);
  swap(a.__isset, b.__isset);
}

Code::Code(const Code& other0) {
  code = other0.code;
  __isset = other0.__isset;
}
Code& Code::operator=(const Code& other1) {
  code = other1.code;
  __isset = other1.__isset;
  return *this;
}
void Code::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Code(";
  out << "code=" << to_string(code);
  out << ")";
}

} // namespace
