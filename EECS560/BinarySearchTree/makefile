lab4: main.o BinarySearchTree.o Node.o Queue.o
	g++ -g -Wall main.o BinarySearchTree.o Node.o Queue.o -o lab4

main.o: main.cpp BinarySearchTree.h Node.h Queue.h
	g++ -g -c -Wall main.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Queue.h Queue.cpp Node.cpp Node.h
	g++ -g -c -Wall BinarySearchTree.cpp

Node.o: Node.cpp Node.h
	g++ -g -c -Wall Node.cpp

Queue.o: Queue.h Queue.cpp Node.cpp Node.h
	g++ -g -c -Wall Queue.cpp

clean:
	rm *.o lab4
	echo clean done
