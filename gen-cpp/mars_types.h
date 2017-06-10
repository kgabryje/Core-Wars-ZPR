/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef mars_TYPES_H
#define mars_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace MARS {

class Code;

class GameInfo;

typedef struct _Code__isset {
  _Code__isset() : code(false) {}
  bool code :1;
} _Code__isset;

class Code : public virtual ::apache::thrift::TBase {
 public:

  Code(const Code&);
  Code& operator=(const Code&);
  Code() : code() {
  }

  virtual ~Code() throw();
  std::string code;

  _Code__isset __isset;

  void __set_code(const std::string& val);

  bool operator == (const Code & rhs) const
  {
    if (!(code == rhs.code))
      return false;
    return true;
  }
  bool operator != (const Code &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Code & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Code &a, Code &b);

inline std::ostream& operator<<(std::ostream& out, const Code& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _GameInfo__isset {
  _GameInfo__isset() : colorTable(false), hasEnded(false), winner(false), firstPlayerProcessesNumber(false), secondPlayerProcessesNumber(false) {}
  bool colorTable :1;
  bool hasEnded :1;
  bool winner :1;
  bool firstPlayerProcessesNumber :1;
  bool secondPlayerProcessesNumber :1;
} _GameInfo__isset;

class GameInfo : public virtual ::apache::thrift::TBase {
 public:

  GameInfo(const GameInfo&);
  GameInfo& operator=(const GameInfo&);
  GameInfo() : hasEnded(0), winner(), firstPlayerProcessesNumber(0), secondPlayerProcessesNumber(0) {
  }

  virtual ~GameInfo() throw();
  std::vector<std::string>  colorTable;
  bool hasEnded;
  std::string winner;
  int16_t firstPlayerProcessesNumber;
  int16_t secondPlayerProcessesNumber;

  _GameInfo__isset __isset;

  void __set_colorTable(const std::vector<std::string> & val);

  void __set_hasEnded(const bool val);

  void __set_winner(const std::string& val);

  void __set_firstPlayerProcessesNumber(const int16_t val);

  void __set_secondPlayerProcessesNumber(const int16_t val);

  bool operator == (const GameInfo & rhs) const
  {
    if (!(colorTable == rhs.colorTable))
      return false;
    if (!(hasEnded == rhs.hasEnded))
      return false;
    if (!(winner == rhs.winner))
      return false;
    if (!(firstPlayerProcessesNumber == rhs.firstPlayerProcessesNumber))
      return false;
    if (!(secondPlayerProcessesNumber == rhs.secondPlayerProcessesNumber))
      return false;
    return true;
  }
  bool operator != (const GameInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GameInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GameInfo &a, GameInfo &b);

inline std::ostream& operator<<(std::ostream& out, const GameInfo& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
