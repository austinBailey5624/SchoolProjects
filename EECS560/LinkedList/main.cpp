/**
*	@file:		main.cpp
*	@author:	Austin Bailey
* 	@date:		8/29/2016
*/

#include <iostream>

#include "LinkedList.h"
#include "Node.h"

int main()
{
	LinkedList* myLinkedList = new LinkedList();
	myLinkedList->populateFromFile();
	bool exit=false;
	int choice;
	while(!exit)
	{
		std::cout << "..........................................................\n";
		std::cout << "Please choose one of the following commands:\n";
		std::cout << "1-insert\n";
		std::cout << "2-print\n";
		std::cout << "3-exit\n";
		std::cout << ">";
		std::cin >> choice;
		if(choice==1)
		{
			std::cout << "Choose a number to be inserted to the list:\n";
			std::cin >> choice;
			myLinkedList->insert(choice);
//			myLinkedList->populateFromFile();
		}
		else if(choice==2)
		{
			std::cout << "List: ";
			myLinkedList->print();
		}
		else if(choice==3)
		{
			std::cout << "Exiting\n";
			delete myLinkedList;
			return(0);
		}
		else
		{
			std::cout << "Invalid input, input a 1 2 or 3";
		}
	}
}
