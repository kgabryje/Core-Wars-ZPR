#include "IncrementService.h"  // As an example

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TJSONProtocol.h>
#include <transport/THttpClient.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

using namespace  ::test;

int main(int argc, char **argv) {
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> bufferedTransport(new TBufferedTransport(socket));
  boost::shared_ptr<TTransport> transport(new THttpClient(bufferedTransport, "localhost", "/"));
  boost::shared_ptr<TProtocol> protocol(new TJSONProtocol(transport));

  IncrementServiceClient client(protocol);
  transport->open();
  client.increment(5);
  transport->close();

  return 0;
}
