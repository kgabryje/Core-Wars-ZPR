#include "IncrementService.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/THttpServer.h>
#include <thrift/protocol/TJSONProtocol.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::test;

class IncrementServiceHandler : virtual public IncrementServiceIf {
 public:
  IncrementServiceHandler() {
    printf("server started\n");
  }

  void ping() {
    printf("ping\n");
  }
  int32_t increment(const int32_t num) {
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

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
