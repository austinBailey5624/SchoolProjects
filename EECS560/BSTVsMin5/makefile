lab6: main.o BinarySearchTree.o Node.o Queue.o Heap.o Timer.o
	g++ -g -Wall -std=c++11 main.o BinarySearchTree.o Node.o Queue.o Heap.o Timer.o -o lab6

main.o: main.cpp BinarySearchTree.h Node.h Queue.h Heap.h
	g++ -g -c -Wall -std=c++11 main.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Queue.h Queue.cpp Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 BinarySearchTree.cpp

Node.o: Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 Node.cpp

Queue.o: Queue.h Queue.cpp Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 Queue.cpp

Heap.o: Heap.cpp Heap.h
	g++ -g -c -Wall -std=c++11 Heap.cpp

Timer.o: Timer.cpp
	g++ -g -c -Wall -std=c++11 Timer.cpp

clean:
	rm *.o lab6
	echo clean done
