/**
*	@file:		CyberChicken.h
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Header File for chicken class
*/    
#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "Chicken.h"
class CyberChicken: public Chicken
{
	public:

		/*	
		*  @pre: none
		*  @post: instance of CyberChicken
		*  @return: instance of CyberChicken
		*/
		CyberChicken();

		/*	
		*  @pre: instance of CyberChicken
		*  @post: const
		*  @return: m_eggs
		*/
		int getCyberEggs()const;

		/*	
		*  @pre: instance of CyberChicken
		*  @post: sets m_eggs to eggs
		*  @return: void
		*/
		void setCyberEggs(int eggs);
};
#endif
