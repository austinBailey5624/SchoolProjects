Lab2: main.o Node.o LinkedList.o
	g++ -Wall -std=c++11 -g main.o Node.o LinkedList.o -o Lab2

main.o: main.cpp Node.h  LinkedList.h
	g++ -Wall -std=c++11 -g -c main.cpp Node.h LinkedList.h

Node.o: Node.cpp Node.h
	g++ -Wall -std=c++11 -g -c Node.cpp Node.h

LinkedList.h: LinkedList.cpp LinkedList.h
	g++ -Wall -std=c++11 -g -c LinkedList.cpp LinkedList.h

clean:
	rm *.o Lab2
