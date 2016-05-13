 Lab1: main.o Colosseum.o Dice.o Pokemon.o
	g++ -Wall -std=c++11 -g main.o Colosseum.o Dice.o Pokemon.o -o Lab1

main.o: main.cpp Colosseum.h Dice.h Pokemon.h
	g++ -Wall -std=c++11 -g -c main.cpp

Colosseum.o: Colosseum.h Colosseum.cpp
	g++ -Wall -std=c++11 -g -c Colosseum.cpp

Dice.o: Dice.h Dice.cpp
	g++ -Wall -std=c++11 -g -c Dice.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -Wall -std=c++11 -g -c Pokemon.cpp

clean:
	rm *.o Lab1
