/**
*	@file: 		main.cpp
*	@author:	Austin Bailey
*	@date:		2.13.2015
*	@purpose:	Space for the utilization of Node and DoubleLinkedList Classes
*/ 
#include<iostream>
#include<string>
#include<stdexcept>
#include "DoubleLinkedList.h"
#include "Node.h"
void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove value\n"
		<<	"6) print list\n"
		<<	"7) Quit\n"
		<< 	"Your choice: ";
}
int main()
{
	int choice;
	int tempi;
	int tempi2;
	bool tempb;
	DoubleLinkedList<int> list;
	while(choice!=7)
	{
		printMenu();
		std::cout << "You chose : ";
		std::cin>>choice;
		if(std::cin.bad())
		{
			std::cout << "Sorry about that, make sure you input a number!\n";
		}
		else if(choice==1)
		{
			std::cout << "Give a value.\n\n";
			std::cin >> tempi;
			list.pushFront(tempi);
		}
		else if(choice==2)
		{
			std::cout << "Give a value.\n\n";
			std::cin >> tempi;
			list.pushBack(tempi);
		}
		else if(choice==3)
		{
			std::cout << "Give a value to insert.\n";
			std::cin >> tempi;
			std::cout << "Pick a value to insert behind.\n\n";
			std::cin >> tempi2;
			std::cout<< "Attempting to insert "<< tempi<< " behind " << tempi2 <<"\n";
			try
			{
				list.insertBehind(tempi, tempi2);
				std::cout << tempi << "inserted behind " << tempi2 << "\n";
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
			}		
		}
		else if(choice==4)
		{
			std::cout << "Give a value to insert.\n";
			std::cin >> tempi;
			std::cout << "Pick a value to insert ahead of.\n\n";
			std::cin >> tempi2;
			std::cout << "Attempting to insert "<<tempi<<" ahead of " << tempi2<<"\n";
			try
			{
				list.insertAhead(tempi, tempi2);
				std::cout << tempi << "inserted ahead of " << tempi2 << "\n";
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
			}
		}
		else if(choice==5)
		{
			std::cout << "Give a value to remove.\n";
			std::cin >> tempi;
			std::cout << "You gave " << tempi << "\n\n";
			try
			{
				tempb=true;
				list.remove(tempi);				
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
				tempb=false;
			}
			if(tempb)
			{
				std::cout << tempi << " removed from the list.";
			}
		}
		else if(choice==6)
		{
			list.printList();
		}
	}
return 0;
}
