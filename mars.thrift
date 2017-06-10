namespace cpp MARS
namespace js MARS

struct Code {
	1: string code
}
service MARS {
	string getCode(),
  string sendMessage(),
  void getMessage(1: string message),
	void receiveFromJS(1: Code c),
	list<string> sendTable(),
	void receiveTable(1: list<string> colorTable)
}
