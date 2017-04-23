GEN_SRC := IncrementService.cpp increment_constants.cpp increment_types.cpp
GEN_OBJ := $(patsubst %.cpp,%.o, $(GEN_SRC))

THRIFT_DIR := /usr/local/include/thrift

INC := -I$(THRIFT_DIR)

.PHONY: all clean

all: server client

%.o: %.cpp
	$(CXX) -Wall $(INC) -c $< -o $@

server: server.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -lthrift

client: client.o $(GEN_OBJ)
	$(CXX) $^ -o $@ -lthrift

clean:
	$(RM) *.o server client
