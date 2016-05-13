/**
*	@file		main.cpp
*	@author		Austin Bailey
*	@date		9/21/2015
*	@purpose	space for the implementation and execution of the DoubleLinkedList and node classes
*/

#include <iostream>
#include <string>
#include <stdexcept>

#include "Node.h"
#include "DoubleLinkedList.h"
#include "Test.h"

int main()
{
	Test myTester(std::cout);
	DoubleLinkedList<int> list;
	bool exit = false;
	int choice;
	int choice2;
	while(!exit)
	{
		std::cout << "Make Choice\n";				//this block outputs menu
		std::cout << "1) push value onto front\n";
		std::cout << "2) push value onto back\n";
		std::cout << "3) insert behind a value\n";
		std::cout << "4) insert ahead of a value\n";
		std::cout << "5) remove front value\n";
		std::cout << "6) remove back value\n";
		std::cout << "7) remove specific value\n";
		std::cout << "8) print list\n";
		std::cout << "9) Quit\n";
		std::cout << "10) Run Tests\n";
		std::cout << "Your choice: ";
		std::cin >> choice;					//determines choice
		std::cout << "You chose : " << choice << "\n";	

		if(choice==1)//case: push value onto front					
		{
			std::cout <<"what value would you like to push onto the front?\n";
			std::cin >> choice;
			list.pushFront(choice);
			
		}
		else if(choice==2)//case: push value onto back
		{
			std::cout << "what value would you like pushed to the back?\n";
			std::cin >> choice;
			list.pushBack(choice);
		}
		else if(choice==3)//case: insert behind a value
		{
			std::cout << "Give a value to insert\n";
			std::cin >> choice;
			std::cout << "Pick a value to insert behind:\n";
			std::cin >> choice2;
			std::cout << "\nAttempting to insert " << choice << " behind " << choice2 << "\n";
			try//try catch catches exceptions thrown by insert behind
			{
				list.insertBehind(choice,choice2);
				std::cout << choice << " inserted behind " << choice2 << "\n";
			}
			catch(std::runtime_error& e)
			{
				std::cout << e.what() << "\n";
			}
		}
		else if(choice==4)// handles case insert ahead
		{
			std::cout << "Give a value to insert\n";
			std::cin >> choice;
			std::cout << "Pick a value to insert ahead of.\n";
			std::cin >> choice2;
			
			try//catches exceptions thrown by insert ahead
			{
				list.insertAhead(choice,choice2);
				std::cout << choice << " inserted ahead of " << choice2 << "\n";
			}
			catch(std::runtime_error& e)
			{
				std::cout << e.what() << "\n";
			}
		}
		else if(choice==5)//handles case remove front value
		{
			if(list.removeFront())
			{
				std::cout << "Front of list removed\n";
			}
			else
			{
				std::cout << "List empty\n";
			}
		}
		else if(choice==6)//handles case remove back value
		{
			if(list.removeBack())
			{
				std::cout << "Back of list removed\n";
			}
			else
			{
				std::cout << "List empty\n";
			}
		}
		else if(choice==7)//handles case remove specific value
		{
			std::cout << "Give a value to remove\n";
			std::cin >> choice;
			std::cout << "you gave " << choice << "\n";
			if(list.remove(choice))
			{
				std::cout << choice << " removed from list\n";
			}
			else
			{
				std::cout << choice << " not in list\n";
			}
		}
		else if(choice==8)//handles print case
		{
			list.printList();
			std::cout << "\n\n";
		}
		else if(choice==9)//handles exit case
		{
			return 0;
		}
		else if(choice==10)//runs tests
		{
			myTester.runTests();
		}
	}
	return 0;
} 
