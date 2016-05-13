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
#include "BinarySearchTree.h"
#include "BSTI.h"
#include "ValueNotFoundException.h"
int main(int argc, char**argv)
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(-32000,32000);
	int size;
	if(argc==0)
	{
		std::cout << "you have not selected a size for the binary tree and will use an empty tree to start with";
		size=0;
	}
	else if(argc==1)
	{
		size=std::stoi(argv[0]);
	}
	else if(argc>1)
	{
		std::cout << "Only your first argument will be used in the program";
		size=std::stoi(argv[0]);
	}
	BSTI<int>* BST = new BinarySearchTree<int>();
	if(size>0)
	{
//		BSTI<int>* BST = new BinarySearchTree<int>();
		int random;
		for(int i=0; i<size;i++)
		{
			random=distribution(generator);
			BST->add(random);
		}		
	}
	bool exit = false;
	int choice;
	int value;
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
				<< "8) Exit\n";
		std::cin >> choice;
		if(choice==1)
		{
			std::cout << "What value would you like to add to the original tree?";
			std::cin >> value;
			if(BST->isEmpty())
			{
				BST->add(value);
			}
			else
			{	
				try
				{
//					if(value=(BST->search(value)));
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
				BSTI<int>* myClone = BST->clone();
			}
			else
			{
				std::cout << "Can only create one clone";	
			}
			hasCopied=true;
		}
		else if(choice==3)
		{
			if(hasDeleted==false)
			{
				std::cout << "Original Tree deleted";
//				delete BST;
			}
			else
			{
				std::cout << "Can only delete once";
			}
		}
		else if(choice==4)
		{

		}
		else if(choice==5)
		{

		}
		else if(choice==6)
		{
			std::cout <<"What number would you like to search for in the original tree?";
			std::cin >> value;
		}
		else if(choice==7)
		{

		}
		else if(choice==8)
		{
			std::cout << "Exiting";
			exit = true;
		}
		else
		{
			std::cout << "Sorry, we couldnt understand your input, please try again";
		}
	}

	return 0;
}

