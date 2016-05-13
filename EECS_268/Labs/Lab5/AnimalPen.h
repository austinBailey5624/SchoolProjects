#ifndef ANIMALPEN_H
#define ANIMALPEN_H
include "Stack.h"
class AnimalPen : public Stack<FarmAnimal*>
{
	public:
		AnimalPen();
		~AnimalPen();
		void addAnimal(FarmAnimal* animal);
		FarmAnimal* peekAtNextAnimal();
		void releaseAnimal();
};
