/**
*	@file:		main.cpp
*	@author:	Austin Bailey
* 	@date:		8/29/2016
*/

#include <iostream>
#include <fstream>
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
		std::cout << "2-delete\n";
		std::cout << "3-reverse\n";
		std::cout << "4-concatenate\n";
		std::cout << "5-print\n";
		std::cout << "6-exit\n";
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
			std::cout << "Choose a number to be deleted from the list\n";
			std::cin >> choice;
			if(myLinkedList->erase(choice))
			{
				std::cout << "Deleted Successfully";
			}
			else
			{
				std::cout << "Could not delete - value not in list";
			}
		}
		else if(choice==3)
		{
			myLinkedList->reverse();
		}
		else if(choice==4)
		{
			std::ifstream file2("data2.txt");
			myLinkedList->concatenate(file2);
		}
		else if(choice==5)
		{
			std::cout << "List: ";
			myLinkedList->print();
		}
		else if(choice==6)
		{
			std::cout << "Exiting\n";
			delete myLinkedList;
			return(0);
		}
		else
		{
			std::cout << "Invalid input, input a number between 1 and 6";
		}
	}
}
