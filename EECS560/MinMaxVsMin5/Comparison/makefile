lab7b: main.o Heap.o minMax.o
	g++ -g -Wall -std=c++11 main.o Heap.o minMax.o -o lab7b

main.o: main.cpp Heap.h minMax.h
	g++ -g -c -Wall -std=c++11 main.cpp

Heap.o: Heap.cpp Heap.h
	g++ -g -c -Wall -std=c++11 Heap.cpp

minMax.o: minMax.cpp minMax.h
	g++ -g -c -Wall -std=c++11 minMax.cpp

clean:
	rm *.o
	rm lab5
	echo clean done
