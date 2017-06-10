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
        cv.notify_one();
        cv.wait(lk, [this]{return received;});
        _return = message;
        received = false;
        waiting = false;
    }

    void getMessage(const std::string& message) {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{return waiting;});
        lk.unlock();
//        if (waiting) {
            std::lock_guard<std::mutex> lk2(m);
            this->message = message;
            received = true;
//        }
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

    void getColorTable(std::vector<std::string> & _return) {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{return table_update;});
        _return = colorTable;
        table_update = false;
    }

    void setColorTable(const std::vector<std::string> & colorTable) {
        this->colorTable = colorTable;
        table_update = true;
        cv.notify_all();
    }

private:
    std::string code;
    std::string message;
    std::vector<std::string> colorTable;

    bool received = false;
    bool waiting = false;
    bool table_update = false;

    std::condition_variable cv;
    std::mutex m;
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
