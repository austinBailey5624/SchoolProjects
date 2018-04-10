 lab3: main.o HashTable.o
	g++ -g -Wall main.o HashTable.o -o lab3

main.o: main.cpp HashTable.h
	g++ -g -c -Wall main.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ -g -c -Wall HashTable.cpp

clean:
	rm *.o lab3
	echo clean done
