Lab8: main.o ValueNotFoundException.o Test.o
	g++ -Wall -std=c++11 -g main.o Test.o ValueNotFoundException.o -o Lab8

main.o: main.cpp Node.h Node.hpp BinarySearchTree.h BinarySearchTree.hpp BSTI.h
	g++ -Wall -std=c++11 -g -c main.cpp

Test.o: Test.cpp Test.h
	g++ -Wall -std=c++11 -g -c Test.cpp


ValueNotFoundException.o: ValueNotFoundException.cpp
	g++ -Wall -std=c++11 -g -c ValueNotFoundException.cpp

clean:
	rm *.o Lab8
