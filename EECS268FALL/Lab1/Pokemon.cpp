/**
*	@file:		Dice.cpp
*	@author:	Austin Bailey
*	@date:		31.8.2015
*	Purpose:	Implementaion of the Pokemon Class
*/

#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{

}

void Pokemon::reduceHP(int amount)
{
	m_hp=m_hp-amount;
}

int Pokemon::getHp()
{
	return m_hp;
}

void Pokemon::setHp(int amount)
{
	m_hp=amount;
}

int Pokemon::getAttackLevel()
{
	return m_attackLevel;
}

void Pokemon::setAttackLevel(int amount)
{
	m_attackLevel=amount;
}

int Pokemon::getDefenseLevel()
{
	return m_defenseLevel;
}

void Pokemon::setDefenseLevel(int amount)
{
	m_defenseLevel=amount;
}

std::string Pokemon::getName()
{
	return m_name;
}

void Pokemon::setName(std::string s)
{
	m_name = s;
}
