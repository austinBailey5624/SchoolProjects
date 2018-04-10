lab1: main.o LinkedList.o Node.o
	g++ -g -Wall main.o LinkedList.o Node.o -o lab1

main.o: main.cpp LinkedList.h Node.h
	g++ -g -c -Wall main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -g -c -Wall LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -c -Wall Node.cpp

clean:
	rm *.o lab1
	echo clean done
