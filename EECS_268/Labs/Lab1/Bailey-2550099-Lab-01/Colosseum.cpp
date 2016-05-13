/**
*	@file:		Colosseum.cpp	
*	@author:	Austin Bailey
*	@date:		1/22/2015
*	@purpose:	Implementation file for Colosseum Class
**/ 
#include "Colosseum.h"
#include <iostream>
#include <string>
//initializes Colosseum instance
Colosseum::Colosseum()
{
	d20=Dice(20);
	d6=Dice();
	d2=Dice(2);
}
//Builds the pokemon
void Colosseum::userBuild(Pokemon& p)
{
	//names the pokemon
	std::cout <<"Please name your pokemon:";
	std::string tempString;
	std::cin >> tempString;
	//ensures that there is at least one character in the name
	while(tempString.length()<1)
	{
		std::cout << "Your name must be at least 1 character long:";
		std::cout << "Please name your Pokemon";
		std::cin >> tempString;
	}
	//sets the name
	p.setName(tempString);
	int statMax;
	//Determines hitpoints
	std::cout << "How many hit points will it have? (1-50)\n";
	int tempi;
	std::cin >> tempi;
	//ensures valid value for hitpoints
	while((tempi<1) || (tempi>50))
	{
		std::cout << "You must have between 1 and 50 hitpoints\n";
		std::cout << "How many hit points will it have? (1-50)\n";
		std::cin >> tempi;
	}
	//sets Hitpoints
	p.setHP(tempi);		
	std::cout << "Split fifty points between attack level and defense level\n";
	std::cout << "Enter your attack level(1-49)\n";
	std::cin >> tempi;
	//Ensures valid value for Attack Level
	while((tempi<1) || (tempi>49))
	{
		std::cout << "You must have an attack level between 1 and 49\n";
		std::cout << "Enter your attack level(1-49)\n";
		std::cin >> tempi;
	}
	//Sets attack level
	p.setAttackLevel(tempi);
	statMax=50-tempi;
	std::cout << "Enter your defense level (1-" << statMax << ")\n";
	std::cin >> tempi;
	//Ensures legal value for DefenseLevel
	while((tempi<1) || (tempi>statMax))
	{
		std::cout << "You must have a defense level between 1 and " << statMax <<"\n";
		std::cout << "Enter your defense level (1-" << statMax << ")\n";
		std::cin >> tempi;
	}
	//sets defense level
	p.setDefenseLevel(tempi);
	
}
bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender)
{	
	//shows who is attacking whom and attack/ defense bonuses
	std::cout << attacker.getName() << " is attacking " << defender.getName()<<"\n";
	int attackBonus = this->d20.roll();
	std::cout << attacker.getName() << " rolls an attack bonus of " << attackBonus << "\n";
	int defenseBonus = this->d20.roll();
	std::cout << defender.getName() << " rolls a defense bonus of " << defenseBonus << "\n";
	if((attacker.getAttackLevel() + attackBonus) >(defender.getDefenseLevel()+defenseBonus))
	{
		//calculates damage
		std::cout<< "The attacker hits dealing 3-D6 damage!\n";
		int roll1= this->d6.roll();
		int roll2= this->d6.roll();
		int roll3= this->d6.roll();
		int damage = roll1+roll2+roll3;
		std::cout<< "The rolls are " << roll1 << ", " << roll2 << ", and " << roll3;
		std::cout<< " totalling: " << damage << " damage!\n";
		//checks to see if the pokemon dies returns true if so, else false
		int tempi=defender.getHP()-damage;
		defender.setHP(tempi);
		if(tempi<1)
		{
			std::cout<< defender.getName() << "has been defeated\n";	
			return true;
		}
		std::cout<<defender.getName()<<" has " << defender.getHP()<< " hit points left\n";
		return false;
	}
	std::cout<<"The attack missed!\n";
	return false;
}
void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	//Determines which character will go first
	std::cout <<"Choosing which player will go first:\n";
	bool oneGoesFirst;
	int tempi = this->d2.roll();
	if(tempi == 1)
	{
		oneGoesFirst=true;
		std::cout << "Player 1 will go first.\n\n";
	}
	else
	{
		oneGoesFirst=false;
		std::cout << "Player 2 will go first.\n\n";
	}
	bool gameOver;
	//Handles rounds
	for(int i=1; i<=10; i++)
	{
		std::cout << "\nRound " << i << "!\n\n";
		if(oneGoesFirst)
		{
			gameOver=attack(p1,p2);
			if(gameOver)
			{
				i=11;
			}
			gameOver=attack(p2,p1);
			if(gameOver)
			{
				i=11;
			}
		}
		else
		{
			gameOver=attack(p2,p1);
			if(gameOver)
			{
				i=11;
			}
			gameOver=attack(p1,p2);
			if(gameOver)
			{
				i=11;
			}
		}			
	}
}
