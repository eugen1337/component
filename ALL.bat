g++ -c ./server/source/Component.cpp -o ./server/build/Component.o
g++ -c ./server/source/main.cpp -o ./server/build/main.o

g++ -shared ./server/build/Component.o ./server/build/main.o -o C:\\component_dll\\server.dll -Wl,--kill-at -lole32 -loleaut32 -luser32

g++ -c ./client/source/Client.cpp -o ./client/build/client.o

g++ ./client/build/client.o -o ./client/build/client.exe -lole32 -loleaut32 -luser32

.\client\build\client.exe

pause