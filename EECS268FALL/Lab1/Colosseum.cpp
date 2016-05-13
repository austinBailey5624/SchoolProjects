/**
*	@file:		Colosseum.cpp
*	@author:	Austin Bailey
*	@date:		31.8.2015
*	Purpose:	Implementation File for the Colosseum class that handles the creation and conflict between the Pokemon.
*/

#include "Colosseum.h"

Colosseum::Colosseum()//:d20(20),d6()
{
	d20 = Dice(20);
	d6 = Dice();
}

void Colosseum::userBuild(Pokemon& p)
{
	//declaration of used variables
	bool loopControl=true;
	std::string temps;
	int tempi;

	//Assignment of name; loop ensures valid name length
	while(loopControl)
	{
		std::cout << "Please name your Pokemon:\n";
		std::cin >> temps;
		if(temps.length()<1)
		{
			std::cout << "Sorry, the name must be at least 1 character long\n";
		}
		else
		{
			loopControl=false;
		}
	}
	p.setName(temps);
	loopControl=true;

	//Assignment of Hitpoints; loop ensures proper HP size
	while(loopControl)
	{
		std::cout << "How many hitpoints will it have? (1-50):\n";
		std::cin >> tempi;
		if(tempi<1||tempi>50)
		{
			std::cout << "Sorry, the hp must be above 1 and below 51\n";
		}
		else
		{
			loopControl=false;
		}
	}
	loopControl=true;
	p.setHp(tempi);

	//Assignment of Attack and Defense Levels; loop ensures proper sizes
	std::cout << "Split 50 points between attack level and defense level\n";
	while(loopControl)
	{
		std::cout << "Enter your attack Level (1-49)\n";
		std::cin >> tempi;
		if(tempi<1||tempi>49)
		{
			std::cout << "Sorry, your attack level must be between 1 and 49\n";
		}
		else
		{
			loopControl=false;
		}		
	}
	loopControl=true;
	p.setAttackLevel(tempi);

	//Assingment of Defense level, maximum possible is based on chosen Attack Level
	while(loopControl)
	{
		std::cout << "Enter your defense level (1-" << 50-p.getAttackLevel() << ")\n";
		std::cin>>tempi;
		if(tempi<1||tempi>(50-p.getAttackLevel()))
		{
			std::cout << "Sorry, your defense level must be between 1 and " << 50-p.getAttackLevel() << "\n";
		}
		else
		{
			loopControl=false;
		} 
	}
	loopControl=true;
}

bool Colosseum::attack(Pokemon& p1, Pokemon& p2)	//true if opponent died from attack, false else
{

	//variables used
	int bonus;	//holds attackers bonus
	int bonus2;	//holds defenders bonus
	int roll1;	//holds value of first roll
	int roll2;	//holds value of second roll
	int roll3;	//holds value of third roll


	//displays who is attacking and defending, rolls bonuses and displays bonuses	
        std::cout << p1.getName() << " is attacking " << p2.getName() << "\n";
	bonus = d20.roll();
	std::cout << p1.getName() << " rolls an attack bonus of " << bonus << "\n";
	bonus2 = d20.roll();
	std::cout << p2.getName() << " rolls a defense bonus of " << bonus2<< "\n";

	//if handles if the attack is successful
	if((p1.getAttackLevel()+bonus)>(p2.getDefenseLevel()+bonus2))
	{
		//calculates damage inflicted
		roll1=d6.roll();
		roll2=d6.roll();
		roll3=d6.roll();
		std::cout << "The rolls are: " << roll1 << ", " << roll2 << ", and " << roll3 << " totaling: " << roll1+roll2+roll3 << " damage!\n";
		p2.setHp(p2.getHp()-(roll1+roll2+roll3)); //inflicts the damage
		if(p2.getHp()<=0)	//handles possiblility of defeated pokemon
		{
			std::cout << p2.getName() << " has been defeated!\n";
			return true;
		}
		else	//handles possiblility of hurt but alive defender
		{
			std::cout << p2.getName() << " has " << p2.getHp() << " hit points left!\n";
			return false;
		}
	}
	else	//handles if the attack is not successful
	{
		std::cout << "The attack missed!\n";
		return false;
	}
    return true;
}

void Colosseum::play(Pokemon& p1, Pokemon& p2)
{
	int i = 0;
	bool battleOver=false;
	while(!battleOver&&i<20)//loop continues while the battle is not over and there are less than 10 rounds
	{

		if(i%2==0)//displays round and handles first half of round
		{
			std::cout << "Round " << (i/2)+1 << "!\n\n";
			battleOver=attack(p1,p2);
		}
		else	//handles second half of round
		{
			battleOver=attack(p2,p1);
			std::cout << "\n";
		}
		i++;	//increments half-round count
	}
}
