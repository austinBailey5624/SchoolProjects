lab7a : main.o minMax.o
	g++ -g -Wall -std=c++11 main.o minMax.o -o lab7a

main.o: main.cpp minMax.h
	g++ -g -c -Wall -std=c++11 main.cpp

minMax.o: minMax.cpp minMax.h
	g++ -g -c -Wall -std=c++11 minMax.cpp

clean:
	rm *.o
	rm lab7a
