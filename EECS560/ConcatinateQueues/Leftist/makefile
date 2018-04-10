lab8a: main.o LeftistHeap.o Node.o Queue.o
	g++ -g -Wall -std=c++11 main.o LeftistHeap.o Node.o Queue.o -o lab8a

main.o: main.cpp LeftistHeap.h Node.h Queue.h
	g++ -g -c -Wall -std=c++11 main.cpp

LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h Queue.cpp Queue.h Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 LeftistHeap.cpp

Node.o: Node.cpp Node.h
	g++ -g -c -Wall Node.cpp

Queue.o: Queue.h Queue.cpp Node.cpp Node.h
	g++ -g -c -Wall Queue.cpp

clean:
	rm *.o lab8a
	echo clean done
