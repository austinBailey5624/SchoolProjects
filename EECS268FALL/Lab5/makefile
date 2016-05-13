Lab5: main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o
	g++ -std=c++11 -g -Wall main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o -o Lab5

main.o: main.cpp StackInterface.h Stack.h Stack.hpp Node.h Node.hpp AnimalPen.h Cow.h
	g++ -std=c++11 -c -g -Wall main.cpp 

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -c -g -Wall PreconditionViolationException.cpp

AnimalPen.o: StackInterface.h Stack.h Node.h AnimalPen.h AnimalPen.cpp FarmAnimal.h
	g++ -std=c++11 -c -g -Wall AnimalPen.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -std=c++11 -c -g -Wall FarmAnimal.cpp

Cow.o: Cow.h Cow.cpp FarmAnimal.h
	g++ -std=c++11 -c -g -Wall Cow.cpp

Chicken.o: Chicken.h Chicken.cpp FarmAnimal.h
	g++ -std=c++11 -c -g -Wall Chicken.cpp

CyberChicken.o: Chicken.h CyberChicken.h CyberChicken.cpp
	g++ -std=c++11 -c -g -Wall CyberChicken.cpp

clean:
	rm *.o Lab5
	echo clean done
