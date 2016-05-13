/**
*	@file:		Cow.cpp
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Implementation File for cow class
*/    
#include "Cow.h"

Cow::Cow()
{
	m_name="Cow";
	m_sound="Moo";
}

double Cow::getMilkProduced()const
{
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons)
{
	m_milkProduced=gallons;
}
