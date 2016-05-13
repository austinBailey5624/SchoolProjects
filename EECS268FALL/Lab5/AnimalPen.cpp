/**
*	@file:		AnimalPen.cpp
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Implementation File for AnimalPen class
*/  

#include "AnimalPen.h"
AnimalPen::AnimalPen()
{

}

AnimalPen::~AnimalPen()
{
//	Node<FarmAnimal*>* temp = peekAtNextAnimal();
	while(size()!=0)
	{
		releaseAnimal();
		pop();
	}
}


void AnimalPen::addAnimal(FarmAnimal* animal)
{
	push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal()const
{
	return peek();
}

void AnimalPen::releaseAnimal()
{
	delete peek();
}

bool AnimalPen::isPenEmpty()const
{	
	return true;
}
