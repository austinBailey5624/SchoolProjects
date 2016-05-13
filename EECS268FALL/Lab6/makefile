Lab6: main.o Test.o
	g++ -Wall -std=c++11 -g main.o Test.o -o Lab6

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -Wall -std=c++11 -g -c main.cpp

Test.o: Test.h Test.cpp
	g++ -Wall -std=c++11 -c -g Test.cpp
clean:
	rm *.o Lab6
