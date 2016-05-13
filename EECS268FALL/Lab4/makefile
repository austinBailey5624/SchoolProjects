Lab4: main.o PreconditionViolationException.o Test.o
	g++ -std=c++11 -g -Wall main.o PreconditionViolationException.o Test.o -o Lab4

main.o: main.cpp Stack.h Node.h Stack.hpp Node.hpp StackInterface.h Test.h Test.cpp
	g++ -std=c++11 -c -g -Wall main.cpp 

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -c -g -Wall PreconditionViolationException.cpp

Test.o: Test.h Test.cpp PreconditionViolationException.h
	g++ -std=c++11 -c -g -Wall Test.cpp
	 
clean:	
	rm *.o Lab4
	echo clean done
