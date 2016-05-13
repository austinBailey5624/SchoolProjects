/**
*	@file:		Chicken.cpp
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Implementation File for chicken class
*/   
#include "Chicken.h"

Chicken::Chicken()
{
	m_name="Chicken";
	m_sound="Cluck";
}

int Chicken::getEggs()const
{
	return m_eggs;
}

void Chicken::setEggs(int eggs)
{
	m_eggs=eggs;
}
