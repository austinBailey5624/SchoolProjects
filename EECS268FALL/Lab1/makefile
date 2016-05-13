Lab1: Pokemon.o Colosseum.o Dice.o main.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o Colosseum.o Dice.o -o Lab1

main.o: main.cpp Pokemon.h Colosseum.h Dice.h
	g++ -std=c++11 -g -Wall -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp 

Colosseum.o: Colosseum.h Colosseum.cpp Dice.h Pokemon.h
	g++ -std=c++11 -g -Wall -c Colosseum.cpp

Dice.o: Dice.h Dice.cpp
	g++ -std=c++11 -g -Wall -c Dice.cpp 

clean:
	rm *.o Lab1
	echo clean done
