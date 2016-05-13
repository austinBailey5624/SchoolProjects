Lab2: main.o LinkedList.o Node.o Test.o
	g++ -std=c++11 -g -Wall main.o LinkedList.o Node.o Test.o -o Lab2

main.o:	main.cpp LinkedList.h Node.h Test.h
	g++ -g -std=c++11 -c -Wall main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.h
	g++ -g -std=c++11 -c -Wall LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -c -Wall Node.cpp

Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -c -Wall Test.cpp

clean:
	rm *.o Lab2
	echo clean done
