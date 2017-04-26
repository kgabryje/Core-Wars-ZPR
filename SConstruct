from os import path, listdir

gen_cpp = [path.join('gen-cpp', f) for f in listdir('gen-cpp') if f.endswith('.cpp')]
client_source = [path.join('logic', f) for f in listdir('logic') if f.endswith('.cpp')] +\
                [path.join('logic', 'parser', f) for f in listdir(path.join('logic', 'parser')) if f.endswith('.cpp')] +\
                [path.join('logic', 'mars', f) for f in listdir(path.join('logic', 'mars')) if f.endswith('.cpp')]

server_source = [path.join('server', 'server.cpp')]

gen_cpp_o = Object(gen_cpp)
# print(gen_cpp_o)
Program('CoreWars', gen_cpp_o + client_source, CPPPATH = ['.', '/usr/local/include/thrift'],\
        LIBS = 'thrift', CPPFLAGS = '-std=c++11')
Program('Server', gen_cpp_o + server_source, CPPPATH = ['.', '/usr/local/include/thrift'],\
        LIBS = 'thrift', CPPFLAGS = '-std=c++11')
Program('tests', 'catch_config.hpp')
