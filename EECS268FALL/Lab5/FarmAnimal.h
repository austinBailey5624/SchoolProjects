/**
*	@file:		FarmAnimal.h
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Header File for FarmAnimal class
*/   
#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <string>
class FarmAnimal
{
	public:
		/*	
		*  @pre: none
		*  @post: Instance of FarmAnimal
		*  @return: Instance of FarmAnimal
		*/
		FarmAnimal();

		/*	
		*  @pre: Instance of FarmAnimal
		*  @post: const
		*  @return: m_name
		*/
		std::string getName()const;

		/*	
		*  @pre: Instance of farm Animal
		*  @post: sets m_name to name
		*  @return: void
		*/
		void setName(std::string name);

		/*	
		*  @pre: instance of Farm animal
		*  @post: const
		*  @return: m_sound
		*/
		std::string getSound()const;

		/*	
		*  @pre: instance of Farm animal
		*  @post: m_sound set to sound
		*  @return: void
		*/
		void setSound(std::string sound);

	protected:
		std::string m_name;
		std::string m_sound;
};
#endif
