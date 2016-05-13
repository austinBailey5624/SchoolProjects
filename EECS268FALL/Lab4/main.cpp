/**
*	@file:		Main.cpp
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	field for the implementation and execution fo the node and stack classes
*/ 
#include <iostream>
#include <stdexcept>
#include <string>

#include "Test.h"
#include "StackInterface.h"
#include "Stack.h"
#include "Node.h"

int main()
{
	StackInterface<int>* lane = new Stack<int>();
	Test myTester(std::cout);
	bool exit=false;
	int choice=0;
	while(!exit)
	{
		std::cout << "Select an action:\n";
		std::cout << "1) Add to stack\n";
		std::cout << "2) See what is at the top of stack\n";
		std::cout << "3) Print all stack\n";
		std::cout << "4) Pop stack\n";
		std::cout << "5) Quit\n";
		std::cout << "6) Run Tests\n";
		std::cout << "Enter Choice:\n";
		std::cin >> choice;
		if(choice==1)
		{
			std::cout << "What is going in stack 1?\n";
			std::cin >> choice;
			lane->push(choice);
			std::cout << choice << " successfully added to stack\n";

		}
		else if(choice==2)
		{
			try
			{
				lane->peek();
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
			}
		}
		else if(choice==3)
		{
			lane->print();
		}
		else if(choice==4)
		{
			lane->pop();
		}
		else if(choice==5)
		{
			delete lane;
			return 0;
		}
		else if(choice==6)
		{
			myTester.runTests();
		}
	}
	return 0;
}
