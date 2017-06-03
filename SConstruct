import os
from os import path, listdir

gen_cpp = [path.join('gen-cpp', f) for f in listdir('gen-cpp') if f.endswith('.cpp')]
client_source = [path.join('logic', folder, f) for folder in ['', 'parser', 'mars', 'view']
                 for f in listdir(path.join('logic', folder)) if f.endswith('.cpp')]
server_source = [path.join('server', 'server.cpp')]
tests_source = [path.join('test_cases',folder, f) for folder in ['parser'] for f in listdir(path.join('test_cases', folder)) if f.endswith('.cpp')]
tests_source.append('test_cases\\catch_init.cpp')
cpppath = ['.','c:\\Users\\Antek\\libs\\thrift-0.10.0\\thrift-0.10.0\\lib\\cpp\\src\\','c:\\Users\\Antek\\libs\\thrift-0.10.0\\thrift-0.10.0\\lib\\cpp\\src\\thrift',
'c:\\Users\\Antek\\libs\\boost_1_64_0\\boost\\']

libpath = ['C:\\Users\\Antek\\libs\\thrift-0.10.0\\thrift-0.10.0\\lib\\cpp\\x64\\Release\\', 'c:\\Users\\Antek\\libs\\boost_1_64_0\\boost\\stage\\x64\\lib\\',
             'C:\\OpenSSL-Win64\\lib']

libs = ['libthrift','libssl','openssl','libcrypto']

env = Environment(CPPPATH = cpppath,
                   LIBS = libs,
                   LIBPATH = libpath,
                   MSVC_VERSION='14.0',
                   CPPFLAGS='/EHsc',
                    )

gen_cpp_o = env.Object(gen_cpp)
client_o = env.Object(client_source)
tests_o = env.Object(tests_source)
tests_files = gen_cpp_o + [f for f in client_o if str(f) != path.join('logic', 'main.obj')] + tests_o

env.Program('CoreWars', gen_cpp_o + client_o)
env.Program('Server', gen_cpp_o + server_source)
env.Program('tests', tests_files)
