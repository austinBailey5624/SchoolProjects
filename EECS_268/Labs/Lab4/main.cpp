#include <stdexcept>
#include <string>
#include <iostream>
#include "Node.h"
#include "PVE.h"
#include "Stack.h"
#include "StackInterface.h"
void printMenu()
{
	
	std::cout << "Select an action:\n"
		<< "1) Add something to stack 1\n"
		<< "2) Add something to stack 2\n"
		<< "3) See what is at the top of stack 1\n"
		<< "4) See what is at the top of stack 2\n"
		<< "5) Print contents in stack 1\n"
		<< "6) Print contents in stack 2\n"
		<< "7) Remove something from stack 1\n"	
		<< "8) Remove something from stack 2\n"
		<< "9) Compare Stacks\n"
		<< "10) Quit\n"
		<< "Enter choice:\n";

}
template <typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2)
{
	std::cout 	<< "\nComparison of stacks:\n"
			<< "lane 1 < lane 2: " <<  (s1 <  s2) 	<< "\n"
			<< "lane 1 > lane 2: " <<  (s1 >  s2) 	<< "\n"
			<< "lane 1 >= lane 2: " << (s1 >= s2) 	<< "\n"
			<< "lane 1 <= lane 2: " << (s1 <= s2) 	<< "\n"
			<< "lane 1 == lane 2: " << (s1 == s2) 	<< "\n"
			<< "lane 1 != lane 2: " << (s1 != s2) 	<< "\n";
}
int main()
{
	StackInterface<std::string>* lane1 = new Stack<std::string>();
	StackInterface<std::string>* lane2 = new Stack<std::string>();	
	int choice;
	std::string temps;
		
	while(choice!=10)
	{
		printMenu();

		std::cin >> choice;
		std::cout<<"You chose "<< choice << "\n";
		
		if(choice==1)
		{
			std::cout << "What is going in Stack 1?:";
			std::cin >> temps;
			lane1->push(temps);
			std::cout << temps << " successfully added to stack 1\n";
		}
		else if(choice==2)
		{
			std::cout << "What is going in Stack 2?\n";
			std::cin >> temps;
			lane2->push(temps);
			std::cout << temps << " successfully added to stack 2\n";
		}
		else if(choice==3)
		{
			std::cout << lane1->peek() <<" is on top of Stack 1\n";
		}
		else if(choice==4)
		{
			std::cout << lane2->peek() <<" is on top of Stack 2\n";
		}
		else if(choice==5)
		{

			lane1->print();
		}
		else if(choice==6)
		{
			lane2->print();
		}

		else if(choice==7)
		{
			temps=lane1->pop();
			std::cout << temps << " removed from Stack 1\n";
		}
		else if(choice==8)
		{
			temps=lane2->pop();
			std::cout << temps << " removed from Stack 2\n";
		}
		else if(choice==9)
		{
			compareStacks(*(lane1),*(lane2));
		}
	}
	std::cout << "Program ending";
	delete lane1;
	delete lane2;
	return 0;
};	 
