namespace cpp MARS 
namespace js MARS

struct Code {
	1: string code
}
service MARS {
	string  getCode(),
	void receiveFromJS(1: Code c)
}
