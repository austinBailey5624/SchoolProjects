Lab3: main.o Test.o
	g++ -std=c++11 -g -Wall main.o Test.o -o Lab3

Test.o: Test.cpp Test.h DoubleLinkedList.h Node.h
	g++ -std=c++11 -g -c -Wall Test.cpp

main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp Test.h
	g++ -std=c++11 -g -c -Wall main.cpp

clean:
	rm *.o Lab3
