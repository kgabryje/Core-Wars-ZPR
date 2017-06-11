#ifndef CORE_WARS_ZPR_SERVERCONNECTOR_H
#define CORE_WARS_ZPR_SERVERCONNECTOR_H

#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/transport/THttpClient.h>
#include <boost/make_shared.hpp>
#include "gen-cpp/MARS.h"
#include "gen-cpp/mars_types.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


class ServerConnector {
public:
    static ServerConnector& getInstance();
    MARS::Code getCode();
    void sendMessage(const std::string& message);
    void setGameInfo(const MARS::GameInfo &gameInfo);
private:
    ServerConnector();
    ServerConnector(const ServerConnector&) = delete;
    ServerConnector& operator=(const ServerConnector&) = delete;

    boost::shared_ptr<TSocket> socket;
    boost::shared_ptr<TTransport> bufferedTransport;
    boost::shared_ptr<TTransport> transport;
    boost::shared_ptr<TProtocol> protocol;
    boost::shared_ptr<MARS::MARSClient> client;
};


#endif //CORE_WARS_ZPR_VIEWCONNECTOR_H
