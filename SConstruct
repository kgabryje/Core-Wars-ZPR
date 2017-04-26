from os import path, listdir

gen_cpp = [path.join('gen-cpp', f) for f in listdir('gen-cpp') if f.endswith('.cpp')]
client_source = [path.join('logic', folder, f) for folder in ['', 'parser', 'mars', 'view']
                for f in listdir(path.join('logic', folder)) if f.endswith('.cpp')]
server_source = [path.join('server', 'server.cpp')]

gen_cpp_o = Object(gen_cpp)

env = Environment(CPPPATH = ['.', '/usr/local/include/thrift'], LIBS = 'thrift', CPPFLAGS = '-std=c++11')
env.Program('CoreWars', gen_cpp_o + client_source)
env.Program('Server', gen_cpp_o + server_source)
Program('tests', 'catch_config.hpp')
