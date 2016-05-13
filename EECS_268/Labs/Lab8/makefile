Lab8: main.o ValueNotFoundException.o
	g++ -Wall -std=c++11 -g main.o -o Lab8

main.o: main.cpp Node.h Node.hpp BinarySearchTree.h BinarySearchTree.hpp BSTI.h
	g++ -Wall -std=c++11 -g -c main.cpp

ValueNotFoundException.o: ValueNotFoundException.cpp
	g++ -Wall -std=c++11 -g -c ValueNotFoundException.cpp

clean:
	rm *.o Lab4
