Lab4: main.o PVE.o
	g++ -Wall -std=c++11 -g main.o PVE.o -o Lab4

main.o: main.cpp Node.h Node.hpp Stack.h Stack.hpp StackInterface.h PVE.h PVE.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

PVE.o: PVE.cpp PVE.h
	g++ -Wall -std=c++11 -g -c PVE.cpp

clean:
	rm *.o Lab4
