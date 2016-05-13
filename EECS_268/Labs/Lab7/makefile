Lab7: main.o NumberFileDriver.o NumberFileGenerator.o Sorts.h SortDriver.o Sorts.hpp test.o
	g++ -Wall -std=c++11 -g main.o NumberFileDriver.o NumberFileGenerator.o Sorts.h SortDriver.o test.o -o Lab7

main.o: main.cpp Sorts.h Sorts.hpp test.h
	g++ -Wall -std=c++11 -g -c main.cpp

test.o: test.h test.cpp
	g++ -Wall -std=c++11 -g -c test.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -Wall -std=c++11 -g -c NumberFileDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -Wall -std=c++11 -g -c NumberFileGenerator.cpp

SortDriver.o:	SortDriver.h SortDriver.cpp
	g++ -Wall -std=c++11 -g -c SortDriver.cpp

clean:
	rm *.o Lab7
