#include "ServerConnector.h"

ServerConnector::ServerConnector() {
    socket = boost::make_shared<TSocket>("localhost", 9090);
    bufferedTransport = boost::make_shared<TBufferedTransport>(socket);
    transport = boost::make_shared<THttpClient>(bufferedTransport, "localhost", "/");
    protocol = boost::make_shared<TJSONProtocol>(transport);
    client = boost::make_shared<MARS::MARSClient>(protocol);
}

ServerConnector& ServerConnector::getInstance() {
    static ServerConnector instance;
    return instance;
}

MARS::Code ServerConnector::getCode() {
    transport->open();
    MARS::Code code;
    client->getCode(code);
    transport->close();
    return code;
}

void ServerConnector::sendMessage(const std::string& message) {
    transport->open();
    client->getMessage(message);
    transport->close();
}

void ServerConnector::setGameInfo(const MARS::GameInfo& gameInfo) {
    transport->open();
    client->setGameInfo(gameInfo);
    transport->close();
}