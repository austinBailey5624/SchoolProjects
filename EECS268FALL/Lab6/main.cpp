 /**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		3/27/2015
*	@purpose:	Space for the utilization of the sorts class
*/
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include "Test.h"
#include "Sorts.h"
void printMenu()
{
	std::cout 	<<	"\n\nSelect a sort:\n"
			<< 	"1) Bubble Sort\n"
			<< 	"2) Insertion Sort\n"
			<< 	"3) Selection Sort\n"
			<< 	"4) Bogo Sort (Use only with small arrays)\n"
			<<	"5) Run Tests\n"
			<< 	"Enter Choice: ";
}
int main()
{
	Test myTester(std::cout);
	Sorts<int>* mySorts = new Sorts<int>;
	std::chrono::duration<double> elapsed;
	double time;
	int choice;
	bool quit=false;
	int size;
	int lowerBound;
	int upperBound;
	char yn;
	while(!quit)
	{
		printMenu();
		std::cin>>choice;


		if(choice==1)
		{
			std::cout << "Input a size for the random array\n";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: \n";
			std::cin >> lowerBound;
			std::cout << "Input a upper bound on the range of random numbers: \n";
			std::cin >> upperBound;
			int* arr = mySorts->createTestArray(size,lowerBound,upperBound);
			std::cout << "Do you want to print the unsorted array?(y,n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the unsorted array:\n[";
				for(int i=0; i<size;i++)
				{	
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}
			std::cout << "Sorting with bubble sort...\n";
			time=mySorts->sortTimer(Sorts<int>::bubbleSort,arr,size);
			std::cout << "Do you want to print the sorted array?(y/n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the sorted array:\n[";
				for(int i=0; i<size;i++)
				{
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}	
			std::cout << size << " numbers were sorted in " << time << " seconds.";		
			delete arr;
		}
		else if(choice==2)
		{	
			std::cout << "Input a size for the random array\n";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: \n";
			std::cin >> lowerBound;
			std::cout << "Input a upper bound on the range of random numbers: \n";
			std::cin >> upperBound;
			int* arr = mySorts->createTestArray(size,lowerBound,upperBound);
			std::cout << "Do you want to print the unsorted array?(y,n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the unsorted array:\n[";
				for(int i=0; i<size;i++)
				{	
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}
			std::cout << "Sorting with insertion sort\n";
			time=mySorts->sortTimer(Sorts<int>::insertionSort,arr,size);
			std::cout << "Do you want to print the sorted array?(y/n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the sorted array:\n[";
				for(int i=0; i<size;i++)
				{
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}	
			std::cout << size << " numbers were sorted in " << time << " seconds.";		
			delete arr;

		}
		else if(choice==3)
		{
			std::cout << "Input a size for the random array\n";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: \n";
			std::cin >> lowerBound;
			std::cout << "Input a upper bound on the range of random numbers: \n";
			std::cin >> upperBound;
			int* arr = mySorts->createTestArray(size,lowerBound,upperBound);
			std::cout << "Do you want to print the unsorted array?(y,n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the unsorted array:\n[";
				for(int i=0; i<size;i++)
				{	
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}
			std::cout << "Sorting with selection sort\n";

			time=mySorts->sortTimer(Sorts<int>::selectionSort, arr,size);
			std::cout << "Do you want to print the sorted array?(y/n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the sorted array:\n[";
				for(int i=0; i<size;i++)
				{
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}	
			std::cout << size << " numbers were sorted in " << time << " seconds.";		
			delete arr;

		}
		else if(choice==4)
		{
			std::cout << "Input a size for the random array\n";
			std::cin >> size;
			std::cout << "Input a lower bound on the range of random numbers: \n";
			std::cin >> lowerBound;
			std::cout << "Input a upper bound on the range of random numbers: \n";
			std::cin >> upperBound;
			int* arr = mySorts->createTestArray(size,lowerBound,upperBound);
			std::cout << "Do you want to print the unsorted array?(y,n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the unsorted array:\n[";
				for(int i=0; i<size;i++)
				{	
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}
			std::cout << "Be sure to use a small number or this may take a while\n";
			time=mySorts->sortTimer(Sorts<int>::bogoSort,arr,size);
			std::cout << "Do you want to print the sorted array?(y/n)\n";
			std::cin >> yn;
			if(yn=='y')
			{
				std::cout << "Here is the sorted array:\n[";
				for(int i=0; i<size;i++)
				{
					if(i==size-1)
					{
						std::cout << arr[i] << "]\n";
					}
					else
					{
						std::cout << arr[i] << ",";
					}				
				}
			}	
			std::cout << size << " numbers were sorted in " << time << " seconds.";		
			delete arr;
		}
		else if(choice==5)
		{
			myTester.runTests();
		}
		std::cout << "Do you want to quit?(y/n)";
		std::cin>>yn;
		if(yn=='y')
		{
			quit=true;
		}
		
	}
	delete mySorts;
	return 0;
}

