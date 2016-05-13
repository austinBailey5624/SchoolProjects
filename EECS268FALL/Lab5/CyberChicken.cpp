/**
*	@file:		CyberChicken.cpp
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Implementation File for CyberChicken class
*/    
#include "CyberChicken.h"

CyberChicken::CyberChicken()
{
	m_name="Cyber Chicken";
	m_sound="Resistance is futile";
}

int CyberChicken::getCyberEggs()const
{
	return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs)
{
	m_eggs=eggs;
}
