 /**
*	@file		main.cpp
*	@author		Austin Bailey
*	@date		9/9/2015
*	@purpose	Place to execute the LinkedList and node classes
*/

#include <iostream>

#include "Node.h"
#include "LinkedList.h"
#include "Test.h"

int main()
{
	bool exit=false;
	int choice;
	LinkedList list;
	Test myTester(std::cout);
	while(!exit)
	{
		std::cout << "Select from the following menu:\n";
		std::cout << "1) Add to the front of the list\n";
		std::cout << "2) Add to the end of the list\n";
		std::cout << "3) Remove from the front of the list\n";
		std::cout << "4) Remove from the back of the list\n";
		std::cout << "5) Print the list\n";
		std::cout << "6) Search for value\n";
		std::cout << "7) Exit\n";
		std::cout << "8) Run tests\n";
		std::cout << "Enter your choice:";
		std::cin >> choice;
		std::cout << "\nYou chose: " << choice << "\n";
		if(choice==1)
		{
			std::cout << "Input a value to add: ";
			std::cin >> choice;
			std::cout << "\nAdding " << choice << " to the list\n";
			list.addFront(choice);
		}
		else if(choice==2)
		{
			std::cout << "Input a value to add: ";
			std::cin >> choice;
			std::cout << "\nAdding " << choice << " to the list\n";
			list.addBack(choice);
		}
		else if(choice==3)
		{
			std::cout << "Attempting removal from front of list.\n";
			if(list.removeFront())
			{
				std::cout << "Removal successful\n";
			}
			else
			{
				std::cout << "Removal not successful\n";
			}
		}
		else if(choice==4)
		{
			std::cout << "Attempting removal from back of list.\n";
			if(list.removeBack())
			{
				std::cout << "Removal successful\n";
			}
			else
			{
				std::cout << "Removal not successful\n";
			}
		}
		else if(choice==5)
		{
			std::cout << "Printing list:\n";
			list.printList();
		}
		else if(choice==6)
		{
			std::cout << "Enter a value to search for: ";
			std::cin >> choice;
			std::cout << "\nSearching for " << choice << "...";
			if(list.search(choice))
			{
				std::cout << choice << " is in the list.\n";
			}
			else
			{
				std::cout << choice << " is not in the list.\n";
			}
		}
		else if(choice==7)
		{
			exit=true;
		}
		else if(choice==8)
		{
			std::cout << "Running Tests\n";
			myTester.runTests();
		}
		else
		{
			std::cout << "Invalid choice.\n";
		}
	}
	return 0;
}
