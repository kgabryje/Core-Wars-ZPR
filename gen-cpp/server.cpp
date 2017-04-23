#include "MARS.h"
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

  void receiveFromJS(std::string& _return) {
      {
          std::lock_guard<std::mutex> lk(m);
          code = _return;
          received = true;
      }
      cv.notify_all();
  }

  void getCode(std::string& _return) {
      std::unique_lock<std::mutex> lk(m);
      std::cerr << "Waiting... \n";
      cv.wait(lk, [this]{return received;});
      std::cerr << "Got it \n";
      _return = code;
      received = false;
  }

private:
    std::string code;
    bool received = false;
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
