namespace cpp MARS
namespace js MARS

struct Code {
	1: string code
}

struct GameInfo {
	1: list<string> colorTable,
	2: bool hasEnded,
	3: string winner,
	4: i16 firstPlayerProcessesNumber,
	5: i16 secondPlayerProcessesNumber
}

service MARS {
	string getCode(),
  string sendMessage(),
  void getMessage(1: string message),
	void receiveFromJS(1: Code c),
	GameInfo getGameInfo(),
	void setGameInfo(1: GameInfo gameInfo)
}
