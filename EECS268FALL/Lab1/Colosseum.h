/**
*	@file:		Colosseum.h
*	@author:	Austin Bailey
*	@date:		31.8.2015
*	Purpose		Header file for the Colosseum Class
*/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include <iostream>	//to use i/o
#include <string>	//to use strings in i/o
#include "Pokemon.h"	//to use class Pokemon in the userBuild, attack and play methods
#include "Dice.h"	//to create and use private member variables d6 and d20
class Colosseum
{
	public:
		/**
		*  @pre null
		*  @post an instance of Colosseum with initialized member variables d6 and d20
		*  @return void
		*/
		Colosseum();
		/**
		*  @pre Instance of Colosseum Class
		*  @post assigns the member variables of the pokemon instance p to user-specified amounts
		*  @return void
		*/
		void userBuild(Pokemon& p);
		/**
		*  @pre Instance of Colosseum Class
		*  @post Reduces defenders hp by the 3d6 if attack is successful
		*  @return true if the defender is killed, false else
		*/
		bool attack(Pokemon& p1, Pokemon& p2);
		/**
		*  @pre Instance of Colosseum Class
		*  @post Executes the up to ten round battle between p1 and p2
		*  @return void
		*/
		void play(Pokemon& p1, Pokemon& p2);

	private:
		Dice d6;
		Dice d20;
};
#endif
