/**
*	@file:		AnimalPen.h
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Header File for AnimalPen class
*/  
#ifndef ANIMALPEN_H
#define ANIMALPEN_H

#include "Stack.h"
#include "FarmAnimal.h"
class AnimalPen: public Stack<FarmAnimal*>
{
	public:
		/*	
		*  @pre: none
		*  @post: instance of Animal Pen
		*  @return: instance of Animal Pen
		*/
		AnimalPen();

		/*	
		*  @pre: instance of Animal Pen
		*  @post: destructor
		*  @return: destructor
		*/
		~AnimalPen();

		/*	
		*  @pre: Instance of Animal Pen
		*  @post: Animal Pen with new animal on top
		*  @return: void
		*/
		void addAnimal(FarmAnimal* animal);

		/*	
		*  @pre: Instance of Animal pen with at least one member
		*  @post: const
		*  @return: pointer to top farm animal
		*/
		FarmAnimal* peekAtNextAnimal()const;
	
		/*	
		*  @pre: Nonempty AnimalPen
		*  @post: pops the stack after releasing the animal
		*  @return: void
		*/
		void releaseAnimal();

		/*	
		*  @pre: Instance of Animal Pen
		*  @post: const
		*  @return: True if empty, false else
		*/
		bool isPenEmpty()const;
};
#endif
