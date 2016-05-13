Lab7: main.o NumberFileDriver.o NumberFileGenerator.o Sorts.h SortDriver.o Sorts.hpp Test.h Test.o
	g++ -Wall -std=c++11 -g main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o Test.o -o Lab7

Test.o: Test.h Test.cpp
	g++ -Wall -std=c++11 -g -c Test.cpp

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -Wall -std=c++11 -g -c main.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -Wall -std=c++11 -g -c NumberFileDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -Wall -std=c++11 -g -c NumberFileGenerator.cpp

SortDriver.o:	SortDriver.h SortDriver.cpp
	g++ -Wall -std=c++11 -g -c SortDriver.cpp

clean:
	rm *.o *.dat Lab7
