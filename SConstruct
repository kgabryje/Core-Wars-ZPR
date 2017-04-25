import os

client_source = ['gen-cpp/' + f for f in os.listdir('gen-cpp') if f.endswith('.cpp')] +\
                ['logic/' + f for f in os.listdir('logic') if f.endswith('.cpp')] +\
                ['logic/parser/' + f for f in os.listdir('logic/parser') if f.endswith('.cpp')] +\
                ['logic/mars/' + f for f in os.listdir('logic/mars') if f.endswith('.cpp')]

server_source = ['gen-cpp/' + f for f in os.listdir('gen-cpp') if f.endswith('.cpp')] +\
                ['server/server.cpp']
Program('CoreWars', client_source, CPPPATH = ['.', '/usr/local/include/thrift'],\
        LIBS = 'thrift', CPPFLAGS = '-std=c++11')
Program('Server', server_source, CPPPATH = ['.', '/usr/local/include/thrift'],\
        LIBS = 'thrift', CPPFLAGS = '-std=c++11')
