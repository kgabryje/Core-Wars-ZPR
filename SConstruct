import os
from os import path, listdir

gen_cpp = [path.join('gen-cpp', f) for f in listdir('gen-cpp') if f.endswith('.cpp')]
client_source = [path.join('logic', folder, f) for folder in ['', 'parser', 'mars', 'view']
                 for f in listdir(path.join('logic', folder)) if f.endswith('.cpp')]
server_source = [path.join('server', 'server.cpp')]
tests_source = [path.join('test_cases',folder, f) for folder in ['parser','mars'] for f in listdir(path.join('test_cases', folder)) if f.endswith('.cpp')]
tests_source.append(path.join('test_cases','catch_init.cpp'))
libs = ['libthrift','libssl','openssl','libcrypto']

env = Environment(CXX = 'g++-6', CPPPATH = '.', LIBS = ['thrift', 'boost_regex'], CPPFLAGS = '-std=c++11')

gen_cpp_o = env.Object(gen_cpp)
client_o = env.Object(client_source)
tests_o = env.Object(tests_source)
tests_files = gen_cpp_o + [f for f in client_o if str(f) != path.join('logic', 'main.o')] + tests_o

env.Program('CoreWars', gen_cpp_o + client_o)
env.Program('Server', gen_cpp_o + server_source)
env.Program('tests', tests_files)
