/**
*	@file:		Cow.h
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Header File for chicken class
*/  
#ifndef COW_H
#define COW_H  

#include "FarmAnimal.h"
class Cow:public FarmAnimal
{
	public:
		/*	
		*  @pre: none
		*  @post: Instance of Cow class
		*  @return: Cow instance 
		*/
		Cow();

		/*	
		*  @pre: Instance of Cow class
		*  @post: const
		*  @return: m_milkProduced
		*/
		double getMilkProduced() const;

		/*	
		*  @pre: Instance of Cow class
		*  @post: sets m_milkProduced to gallons
		*  @return: void
		*/
		void setMilkProduced(double gallons);

	protected:
		double m_milkProduced;
};
#endif
