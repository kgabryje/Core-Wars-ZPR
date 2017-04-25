from os import path, listdir

client_source = [path.join('gen-cpp', f) for f in listdir('gen-cpp') if f.endswith('.cpp')] +\
                [path.join('logic', f) for f in listdir('logic') if f.endswith('.cpp')] +\
                [path.join('logic', 'parser', f) for f in listdir(path.join('logic', 'parser')) if f.endswith('.cpp')] +\
                [path.join('logic', 'mars', f) for f in listdir(path.join('logic', 'mars')) if f.endswith('.cpp')]

server_source = [path.join('gen-cpp/', f) for f in listdir('gen-cpp') if f.endswith('.cpp')] +\
                [path.join('server', 'server.cpp')]
Program('CoreWars', client_source, CPPPATH = ['.', '/usr/local/include/thrift'],\
        LIBS = 'thrift', CPPFLAGS = '-std=c++11')
Program('Server', server_source, CPPPATH = ['.', '/usr/local/include/thrift'],\
        LIBS = 'thrift', CPPFLAGS = '-std=c++11')
