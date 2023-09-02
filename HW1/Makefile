all: main

main: main.o permutate.o
	g++ main.o permutate.o -o main

main.o: main.cpp
	g++ -c main.cpp

permutate.o: permutate.cpp 
	g++ -c permutate.cpp

clean: 
	-rm *.o main


