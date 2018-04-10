project1: main.o AttValuePair.o Rule.o
	g++ -std=c++11 -g -Wall AttValuePair.o main.o Rule.o -o project1

main.o: main.c++ AttValuePair.h AttValuePair.c++ Rule.h Rule.c++
	g++ -std=c++11 -g -c -Wall main.c++ AttValuePair.h AttValuePair.c++ Rule.h Rule.c++

AttValuePair.o: AttValuePair.h AttValuePair.c++
	g++ -std=c++11 -g -c -Wall AttValuePair.h AttValuePair.c++

Rule.o: Rule.h Rule.c++ AttValuePair.h AttValuePair.c++
	g++ -std=c++11 -g -c -Wall Rule.h Rule.c++ AttValuePair.h AttValuePair.c++

clean:
	rm *.o project1
