lab9: main.o SkewHeap.o Node.o Queue.o LeftistHeap.o
	g++ -g -Wall -std=c++11 main.o SkewHeap.o LeftistHeap.o Node.o Queue.o -o lab9

main.o: main.cpp SkewHeap.h Node.h Queue.h LeftistHeap.h
	g++ -g -c -Wall -std=c++11 main.cpp

SkewHeap.o: SkewHeap.cpp SkewHeap.h Queue.cpp Queue.h Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 SkewHeap.cpp

LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h Queue.cpp Queue.h Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 LeftistHeap.cpp

Node.o: Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 Node.cpp

Queue.o: Queue.h Queue.cpp Node.cpp Node.h
	g++ -g -c -Wall -std=c++11 Queue.cpp

clean:
	rm *.o lab9
	echo clean done
