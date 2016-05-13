/**
*	@file:		FarmAnimal.cpp
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Implementation File for FarmAnimal class
*/    
#include "FarmAnimal.h"
FarmAnimal::FarmAnimal()
{
	m_name="unset";
	m_sound="unset";
}

std::string FarmAnimal::getName()const
{
	return m_name;
}

void FarmAnimal::setName(std::string name)
{
	m_name=name;
}

std::string FarmAnimal::getSound()const
{
	return m_sound;
}

void FarmAnimal::setSound(std::string sound)
{
	m_sound=sound;
}
