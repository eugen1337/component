g++ -c ./server/source/IFSManager.cpp -o ./server/build/IFSManager.o

move /Y .\server\build\IFSManager.o .\client\build\lib 

g++ -c ./client/source/client.cpp  -o ./client/build/client.o
g++ ./client/build/client.o ./client/build/lib/IFSManager.o -o ./client/build/client.exe
"client/build/client.exe"

pause