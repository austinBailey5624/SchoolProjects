/**
*	@file:		Pokemon.h
*	@author:	Austin Bailey
*	@date:		31.8.2015
*	Purpose:	Header file of the Pokemon Class, used to define the Pokmeon object, member variables and member methods
*/

#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes a Pokemon instance
		*  @return Initialzed Pokemon with unassigned member variables
		*/
		Pokemon();
		/**
		*  @pre Instance of Pokemon Class
		*  @post Reduces the instances HP by amount
		*  @return void
		*/
		void reduceHP(int amount);
		/**
		*  @pre Instance of Pokemon Class
		*  @post Returns the value of the private member variable m_hp
		*  @return value of private member variable m_hp
		*/		
		int getHp();
		/**
		*  @pre Instance of Pokemon Class
		*  @post Pokemon with private member variable m_hp set to amount
		*  @return void
		*/
		void setHp(int amount);
		/**
		*  @pre Instance of Pokemon Class
		*  @post instance's member variables unchanged
		*  @return the value of the private member variable m_attackLevel
		*/
		int getAttackLevel();
		/**
		*  @pre Instance of Pokemon Class
		*  @post sets the instances private member variable m_attackLevel to amount
		*  @return void
		*/
		void setAttackLevel(int amount);
		/**
		*  @pre Instance of Pokemon Class
		*  @post instance member variables unchanged
		*  @return the value of private member variable m_defenseLevel
		*/
		int getDefenseLevel();
		/**
		*  @pre Instance of Pokemon Class
		*  @post sets the private member variable m_defenseLevel to amount
		*  @return void
		*/
		void setDefenseLevel(int amount);
		/**
		*  @pre Instance of Pokemon Class
		*  @post member variables remain unchanged
		*  @return private member variable m_name
		*/
		std::string getName();
		/**
		*  @pre Instance of Pokemon Class
		*  @post Sets the private member variable m_name to s
		*  @return void
		*/
		void setName(std::string s);

	private:
		int m_hp;
		int m_attackLevel;
		int m_defenseLevel;
		std::string m_name;
	
};
#endif
