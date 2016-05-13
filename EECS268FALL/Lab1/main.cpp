 /**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		31.8.2015
*	Purpose:	Space for the implementation and execution of the Pokemon and Colosseum Calsses and their methods
*/
#include "Colosseum.h"
#include "Dice.h"
#include "Pokemon.h"
int main()
{
	//Declaration of variables
	char yn;
	Pokemon p1;
	Pokemon p2;
	Colosseum c1;

	while(true)
	{
		//Pokemon Creation
		std::cout << "Player 1, build your Pokemon!\n=====================\n";
		c1.userBuild(p1);
		std::cout << "Player 2, build your Pokmeon!\n=====================\n";
		c1.userBuild(p2);
		
		//Dice used to determine who goes first
		Dice d2 = Dice(2);
		

		//Fifty-Fifty chance d2.roll returns 1, determines who goes first
		if(d2.roll()==1)
		{
			std::cout << "Player 1 goes first!\n\n\n";
			c1.play(p1,p2);
		}
		else
		{
			std::cout << "Player 2 goes first!\n\n\n";
			c1.play(p2,p1);
		}
		std::cout<< "Would you like to play again? (y/n)";
		std::cin >> yn;
		if(yn=='n')
		{
			return 0;
		}
	}
	return 0;
}
