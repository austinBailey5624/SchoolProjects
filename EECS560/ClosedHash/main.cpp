/**
*	@file:		main.cpp
*	@author:	Austin Bailey
* 	@date:		9.15.2016
*/

#include <iostream>
#include <fstream>
#include "HashTable.h"

int main()
{
	HashTable* myHashTable = new HashTable();
	int choice;
	bool tempb;
	bool exit = false;
	while(!exit)
	{
		std::cout << "Please choose one of the following commands:\n";
		std::cout << "1- insert\n2- delete\n3- print\n4- exit\n";
		std::cin >> choice;
		if(choice==1)
		{
			std::cout << "Which number do you want to insert into the hash table?\n";
			std::cin >> choice;
			tempb=myHashTable->insert(choice);
			if(tempb)
			{
				std::cout << choice << " was successfully inserted into the table\n";
			}
			else
			{
				std::cout << "Value not inserted\n";
			}
		}
		else if(choice==2)
		{
			std::cout << "Which number do you want to remove from the hash table?\n";
			std::cin >> choice;
			if(myHashTable->contains(choice))
			{
				tempb=myHashTable->remove(choice);
			}
			else
			{
				std::cout << "The HashTable does not contain the value " << choice;
				std::cout << " no removal was preformed\n";
			}
			if(tempb)
			{
				std::cout << "Removal of " << choice << " was preformed successfully\n";
			}
			else
			{
				std::cout << "Could not remove " << choice << "\n";
			}
		}
		else if(choice==3)
		{
			myHashTable->print();
		}
		else if(choice==4)
		{
			std::cout << "Exiting\n";
			return 0;
		}
		else 
		{
			std::cout << "Did not understand your input, please input a 1 2 3 or 4\n";
		}
	}

	return 0;
}
