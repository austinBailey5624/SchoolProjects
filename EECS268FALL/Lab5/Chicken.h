/**
*	@file:		Chicken.h
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Header File for chicken class
*/    
#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"
class Chicken:public FarmAnimal
{
	public:
		Chicken();
	
	protected:
		/*	
		*  @pre: instance of chicken
		*  @post: const
		*  @return: m_eggs
		*/
		int getEggs()const;

		/*	
		*  @pre: instance of chicken
		*  @post: sets m_eggs to eggs
		*  @return: void
		*/
		void setEggs(int eggs);

		int m_eggs;
};
#endif
