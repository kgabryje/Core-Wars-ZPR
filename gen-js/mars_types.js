//
// Autogenerated by Thrift Compiler (0.10.0)
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//


if (typeof MARS === 'undefined') {
  MARS = {};
}
MARS.Code = function(args) {
  this.code = null;
  if (args) {
    if (args.code !== undefined && args.code !== null) {
      this.code = args.code;
    }
  }
};
MARS.Code.prototype = {};
MARS.Code.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.STRING) {
        this.code = input.readString().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 0:
        input.skip(ftype);
        break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

MARS.Code.prototype.write = function(output) {
  output.writeStructBegin('Code');
  if (this.code !== null && this.code !== undefined) {
    output.writeFieldBegin('code', Thrift.Type.STRING, 1);
    output.writeString(this.code);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

