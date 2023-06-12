g++ -c ./server/simple/source/Component.cpp -o ./server/simple/build/Component.o
g++ -c ./server/simple/source/main.cpp -o ./server/simple/build/main.o

g++ -shared ./server/simple/build/Component.o ./server/simple/build/main.o -o C:\\component_dll\\simple_server.dll -Wl,--kill-at -lole32 -loleaut32 -luser32

g++ -c ./server/super/source/Component.cpp -o ./server/super/build/Component.o
g++ -c ./server/super/source/Methods.cpp -o ./server/super/build/Methods.o
g++ -c ./server/super/source/main.cpp -o ./server/super/build/main.o

g++ -shared ./server/super/build/Component.o ./server/super/build/main.o ./server/super/build/Methods.o -o C:\\component_dll\\server.dll -Wl,--kill-at -lole32 -loleaut32 -luser32

g++ -c ./client/source/Client.cpp -o ./client/build/client.o

g++ ./client/build/client.o -o .\client\build\client.exe -lole32 -loleaut32 -luser32

.\client\build\client.exe

pause