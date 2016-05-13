/**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		10/5/2015
*	@purpose:	Space for implementation of farm animal and associated classes
*/   
#include "StackInterface.h"
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"

#include <iostream>
#include <stdexcept>
#include <string>
int main()
{
	AnimalPen* pen= new AnimalPen();	//creates the pen where we store the animals

	double gallonsTotal=0.0;		//dummy variables used to assign values to member variables
	int eggsTotal=0;
	std::string choices="";
	int choice;
	double d;				


	FarmAnimal* fa;				//initialization of recyclable pointers to farmAnimals (and derived classes)
	Cow* cow;
	Chicken* chicken;
	CyberChicken* cc;


	while(choices.compare("y")!=0)		//Continues adding while choices is not equal to "y", so user controlls the end of the while loop
	{

		std::cout << "Select an animal to add to the pen\n";			//Prints the menu for user
		std::cout << "1.) Cow (produces milk)\n";
		std::cout << "2.) Chicken (cannot lay eggs)\n";
		std::cout << "3.) Cyber Chicken (seems dangerous, but lays eggs)\n";
		
		std::cin >> choice;							//gets choice from user
		if(choice==1)								//Handles case add Cow
		{
			fa = new Cow();
			cow = static_cast<Cow*>(fa);
			std::cout << "How many gallons of milk did this cow produce?:\n";
			std::cin>>d;
			cow->setMilkProduced(d);
			pen->addAnimal(fa);
		}
		else if(choice==2)							//Handles case Add chicken
		{
			fa = new Chicken();
			chicken= static_cast<Chicken*>(fa);
			std::cout << "Adding eggless chicken to the men? OK. You're the boss.\n";
			pen->addAnimal(fa);
		}
		else if(choice==3)							//Handles case add cyberChicken
		{
			fa= new CyberChicken();
			cc=static_cast<CyberChicken*>(fa);
			std::cout << "How many eggs did this cyber chicken produce?:\n";
			std::cin >> choice;
			cc->setCyberEggs(choice);
			pen->addAnimal(fa);
		}
		else									//Incase input is not a numer between 1 and 3
		{
			std::cout << "sorry, I couldn't understand your input\n";
		}

		std::cout << "Done adding animals? (y/n)";				//Displays decision to user
		std::cin >> choices;							//user interacts with program determining if the loop ends
	}

	try
	{
		while(pen->peekAtNextAnimal()!=nullptr)					//Looping condition ensures that program ends when pen is empty
		{
			fa=pen->peekAtNextAnimal();
			if(fa->getName().compare("Cow")==0)				//Handles cow case
			{
				cow = static_cast<Cow*>(fa);				//static cast to cow in order to access m_milkProduced
				std::cout << "This cow produced " << cow->getMilkProduced()<< " gallons of milk\n";
				std::cout << "Upon release the " << cow->getName() << " said " << cow->getSound() <<"\n";
				gallonsTotal=gallonsTotal+cow->getMilkProduced();
			}
			else if(fa->getName().compare("Chicken")==0)			//Handles chicken case
			{
				chicken=static_cast<Chicken*>(fa);			//static cast to chicken
				std::cout << "Upon release the " << chicken->getName() << " said " << chicken->getSound() << "\n";
			}
			else if(fa->getName().compare("Cyber Chicken")==0)		//Handles cyberChicken case
			{
				cc=static_cast<CyberChicken*>(fa);			//static cast to cyber chicken to access derived member variables
				std::cout << "This Cyber Chicken laid " << cc->getCyberEggs() << " cyber eggs. Humanity is in trouble\n";
				eggsTotal=eggsTotal+cc->getCyberEggs();
				std::cout << "Upon release the " << cc->getName() << " said " << cc->getSound()<< "\n";
			}

			pen->releaseAnimal();
			pen->pop();
		}
	}
	catch(std::exception& e)							//handles peeking exceptions
	{

	}
	std::cout << "Your farm produced " << gallonsTotal << " gallons of milk and " << eggsTotal << " eggs.\n";//outputs results to user
	delete pen;									//takes care of memory
	return 0;									//Ends program
}
