g++ -c ./server/source/Components.cpp -o ./server/build/Components.o

g++ -shared ./server/build/Components.o -o ./manager/server.dll -Wl,--kill-at

g++ -c ./manager/manager.cpp -o ./manager/manager.o

g++ -shared ./manager/manager.o -o ./client/build/lib/manager.dll -Wl,--kill-at


g++ -c ./client/source/client.cpp  -o ./client/build/client.o
g++ ./client/build/client.o -o ./client/build/client.exe
"client/build/client.exe"

pause