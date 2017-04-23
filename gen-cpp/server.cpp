#include "IncrementService.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/THttpServer.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TThreadedServer.h>

#include <unistd.h>
#include <condition_variable>
#include <thread>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::test;

std::condition_variable cv;
std::mutex m;

bool i = false;

class IncrementServiceHandler : virtual public IncrementServiceIf {
 public:
  IncrementServiceHandler() {
    printf("server started\n");
  }

  void unlock() {
    {
      std::lock_guard<std::mutex> lk(m);
      i = true;
      std::cerr << "Unlocking...\n";
    }
    cv.notify_all();
  }

  int32_t increment(const int32_t num) {
    std::unique_lock<std::mutex> lk(m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, []{return i;});
    i = false;
    printf("increment from %d to %d\n", num, num + 1);
    return num + 1;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<IncrementServiceHandler> handler(new IncrementServiceHandler());
  shared_ptr<TProcessor> processor(new IncrementServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new THttpServerTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

  TThreadedServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
