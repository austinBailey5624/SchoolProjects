/**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		4/10/2015
*	@purpose:	file utilizing the classes
**/  
#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <stdexcept>
#include "Test.h"
#include "BinarySearchTree.h"
#include "BSTI.h"
#include "ValueNotFoundException.h"
int main(int argc, char**argv)
{
	using namespace std;
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(-32000,32000);
	int size=0;
	if(argc==1)
	{
		std::cout << "you have not selected a size for the binary tree and will use an empty tree to start with\n";
		size=0;
}
	else if(argc==2)
	{
		size=std::stoi(argv[1]);
	}
	else if(argc>2)
	{
		std::cout << "Only your first argument will be used in the program";
		size=std::stoi(argv[1]);
	}
	else
	{
		size=0;
	}
	BSTI<int>* BST = new BinarySearchTree<int>();
	if(size>0)
	{
		int random;
		for(int i=0; i<size;i++)
		{
			random=distribution(generator);
			BST->add(random);
		}		
	}
	Test myTester;
	bool exit = false;
	BSTI<int>* myClone=nullptr;
	int choice;
	int value;
	bool tempb;
	bool hasCopied=false;
	bool hasDeleted=false;
	while(!exit)
	{
		std::cout 	<< "1) Add more values to the original Tree\n"
				<< "2) Copy the original tree\n"
				<< "3) Delete the original tree (one time only)\n"
				<< "4) Print original tree\n"
				<< "5) Print copy\n"
				<< "6) Search origial tree\n"
				<< "7) Search Copy\n"
				<< "8) Exit\n"
				<< "9) Run Tests\n";
		std::cin >> choice;
		if(choice==1)
		{
			std::cout << "What value would you like to add to the original tree?\n";
			std::cout << "mark1";
			cin >> value;
			std::cout << "mark2";
			if(BST->isEmpty())
			{
				std::cout << "got here";
				BST->add(value);
			}
			else
			{	
				try
				{
					if(value==(BST->search(value)));
					BST->add(value);
				}
				catch(std::exception e)
				{
					e.what();
				}
			}
		}
		else if(choice==2)
		{
			if(hasCopied==false)
			{
				sdt::cout << "
				myClone = BST->clone();
			}
			else
			{
				std::cout << "Can only create one clone\n";	
			}
			hasCopied=true;
		}
		else if(choice==3)
		{
			if(hasDeleted==false)
			{
				std::cout << "Original Tree deleted\n";
				delete BST;
			}
			else
			{
				std::cout << "Can only delete once\n";
			}
		}
		else if(choice==4)
		{
			std::cout << "in what order do you want the original tree printed?\n";
			std::cout << "1) Preorder\n2)InOrder\n3)PostOrder\n";
			std::cin >> choice;
			if(choice==1)
			{
				BST->printTree(PRE_ORDER);
			}
			else if(choice==2)
			{
				BST->printTree(IN_ORDER);
			}
			else if(choice==3)
			{
				BST->printTree(POST_ORDER);
			}
		}
		else if(choice==5)
		{
			if(hasCopied)
			{
				std::cout << "in what order do you want the copy tree printed?\n";
				std::cout << "1) Preorder\n2)InOrder\n3)PostOrder\n";
				std::cin >> choice;
				if(choice==1)
				{
					myClone->printTree(PRE_ORDER);
				}
				else if(choice==2)
				{
					myClone->printTree(IN_ORDER);
				}
				else if(choice==3)
				{
					myClone->printTree(POST_ORDER);
				}
			}
			else
			{
				std::cout << "You haven't copied the tree yet!";
			}	
		}
		else if(choice==6)
		{
			std::cout <<"What number would you like to search for in the original tree?\n";
			std::cin >> value;
			try
			{
				tempb=BST->search(value);
				if(tempb)
				{
					std::cout << value << " is in the original tree!\n";
				}
				else
				{
					std::cout << value << " is not in the original tree...\n";
				}
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
			}
		}
		else if(choice==7)
		{
			std::cout << "What number would you like to search for in the copy tree?\n";
			std::cin >> value;
			try
			{
				tempb=myClone->search(value);
				if(tempb)
				{
					std::cout << value << " is in the cloned tree!\n";
				}
				else
				{
					std::cout << value << " is not in the cloned tree...\n";
				}
			}
			catch(std::exception& e)
			{
				std::cout << e.what();
			}


		}
		else if(choice==8)
		{
			std::cout << "Exiting";
			exit = true;
		}
		else if(choice==9)
		{
			myTester.runTests();
		}
		else
		{
			std::cout << "Sorry, we couldnt understand your input, please try again";
		}
	}

	return 0;
}

