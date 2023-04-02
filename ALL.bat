g++ -c ./server/source/FSManager.cpp -o ./server/build/FSManager.o
g++ -c ./server/source/FSMFactory.cpp -o ./server/build/FSMFactory.o

move /Y .\server\build\FSManager.o .\client\build\lib 
move /Y .\server\build\FSMFactory.o .\client\build\lib 

g++ -c ./client/source/client.cpp  -o ./client/build/client.o
g++ ./client/build/client.o ./client/build/lib/FSManager.o ./client/build/lib/FSMFactory.o -o ./client/build/client.exe
"client/build/client.exe"

pause