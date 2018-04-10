lab5: main.o Heap.o
	g++ -g -Wall -std=c++11 main.o Heap.o -o lab5

main.o: main.cpp Heap.h
	g++ -g -c -Wall -std=c++11 main.cpp

Heap.o: Heap.cpp Heap.h
	g++ -g -c -Wall -std=c++11 Heap.cpp

clean:
	rm *.o
	rm lab5
	echo clean done
