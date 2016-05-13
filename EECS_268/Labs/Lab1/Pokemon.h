/**
*	@file: Pokemon.h
* 	@author: Austin Bailey
*	@Date: 1/22/2015
**/

#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
public:
	/**
	*  @pre None
	*  @post Creates and initializes a Pokemon instance
	*  @return Initialzed Pokemon instance
	*/
	Pokemon();

	/**
	*  @pre Pokemon instance
	*  @post Pokmeon instance with m_hp reduced by amount
	*  @return none
	*/
	void reduceHP(int amount);

	/**
	*  @pre Pokemon instance
	*  @post Pokemon instance has an m_hp value of hp
	*  @return none
	*/
	void setHP(int hp);

	/**
	*  @pre Pokemon instance with set m_hp
	*  @post no change to instance
	*  @return The value of the hp of the instance
	*/
	int getHP()const;

	/**
	*  @pre Pokmeon instance
	*  @post instance has an m_attackLevel value of attackLevel
	*  @return Initialzed Pokemon instance
	*/
	void setAttackLevel(int attackLevel);

	/**
	*  @pre Pokemon instance with a set Attack Level
	*  @post no change to instance
	*  @return the value of m_attackLevel
	*/
	int getAttackLevel()const;

	/**
	*  @pre Pokemon instance
	*  @post instance's m_defenseLevel is set to defenseLevel 
	*  @return none
	*/
	void setDefenseLevel(int defenseLevel);

	/**
	*  @pre Pokmeon instance with a set defense level
	*  @post no change to instance
	*  @return the value of m_defenseLevel
	*/
	int getDefenseLevel()const;

	/**
	*  @pre Pokmeon instance
	*  @post Creates and initializes a Pokemon instance
	*  @return Initialzed Pokemon instance
	*/
	void setName(std::string name);

	/**
	*  @pre Pokmeon instance with m_name set
	*  @post does not change instance
	*  @return value of m_name
	*/
	std::string getName()const;

private:
	int m_hp;		//How many hitpoints the pokemon has
	int m_attackLevel;	//attack level of the pokemon
	int m_defenseLevel;	//defense level of the pokemon
	std::string m_name;		//name of the pokemon
};









#endif
