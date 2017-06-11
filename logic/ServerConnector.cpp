#include "ServerConnector.h"

/**
 * Initializes c++ client connected to server
 */
ServerConnector::ServerConnector() {
    socket = boost::make_shared<TSocket>("localhost", 9090);
    bufferedTransport = boost::make_shared<TBufferedTransport>(socket);
    transport = boost::make_shared<THttpClient>(bufferedTransport, "localhost", "/");
    protocol = boost::make_shared<TJSONProtocol>(transport);
    client = boost::make_shared<MARS::MARSClient>(protocol);
}

/**
 * @return instance of ServerConnector
 */
ServerConnector& ServerConnector::getInstance() {
    static ServerConnector instance;
    return instance;
}

/**
 * Gets warrior's code from server
 * @return warrior code
 */
MARS::Code ServerConnector::getCode() {
    transport->open();
    MARS::Code code;
    client->getCode(code);
    transport->close();
    return code;
}

/**
 * Relays message about whether warrior code parsing succeeded to server
 * @param message
 */
void ServerConnector::sendMessage(const std::string& message) {
    transport->open();
    client->getMessage(message);
    transport->close();
}

/**
 * Sends game information to server
 * @param gameInfo struct with vector of colors and other game information
 */
void ServerConnector::setGameInfo(const MARS::GameInfo& gameInfo) {
    transport->open();
    client->setGameInfo(gameInfo);
    transport->close();
}