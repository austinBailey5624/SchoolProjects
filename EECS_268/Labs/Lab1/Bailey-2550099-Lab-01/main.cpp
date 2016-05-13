/**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		1/22/2015
*	@purpose:	Control flow of program, most work is done by methods
**/
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"
#include "Colosseum.h"
int main()
{
Pokemon p1;
Pokemon p2;
Colosseum c1;
std::string temps;
bool wannaPlay = true;
while(wannaPlay)
{
	std::cout <<"Player 1, build your Pokemon!\n=====================\n";
	c1.userBuild(p1);
	std::cout <<"Player 2, build your pokmeon!\n=====================\n";
	c1.userBuild(p2);
	c1.play(p1,p2);
	std::cout <<"Do you want to play again? (y/n):";
	std::cin >> temps;
	if(temps=="n")
	{
		return 0;
	}
}
return 0;
}
