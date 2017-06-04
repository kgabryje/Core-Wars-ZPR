#include "../gen-cpp/MARS.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/THttpServer.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TThreadedServer.h>

#include <condition_variable>
#include <thread>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::MARS;

std::condition_variable cv;
std::mutex m;

class MARSHandler : virtual public MARSIf {
public:
    MARSHandler() {
    printf("server started\n");
    }

    void receiveFromJS(const Code& c) {
      if (waiting) {
          {
              std::lock_guard<std::mutex> lk(m);
              code = c.code;
              received = true;
          }
          cv.notify_all();
      }
    }

    void sendMessage(std::string& _return) {
        std::unique_lock<std::mutex> lk(m);
        waiting = true;
        cv.wait(lk, [this]{return received;});
        _return = message;
        received = false;
        waiting = false;
    }

    void getMessage(const std::string& message) {
        if (waiting) {
            std::lock_guard<std::mutex> lk(m);
            this->message = message;
            received = true;
        }
        cv.notify_all();
    }

    void getCode(std::string& _return) {
      std::unique_lock<std::mutex> lk(m);
      std::cerr << "Waiting... \n";
      waiting = true;
      cv.wait(lk, [this]{return received;});
      std::cerr << "Got it \n";
      _return = code;
      received = false;
      waiting = false;
    }

private:
    std::string code;
    std::string message;
    bool received = false;
    bool waiting = false;
};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<MARSHandler> handler(new MARSHandler());
  shared_ptr<TProcessor> processor(new MARSProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new THttpServerTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

  TThreadedServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
