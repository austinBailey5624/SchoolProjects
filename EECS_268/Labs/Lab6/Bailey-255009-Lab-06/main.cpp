 /**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		*3/27/2015
*	@purpose:	Space for the utilization of the sorts class
*/
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include "Sorts.h"
void printMenu()
{
	std::cout 	<<	"\n\nSelect a sort:\n"
			<< 	"1) Bubble Sort\n"
			<< 	"2) Insertion Sort\n"
			<< 	"3) Selection Sort\n"
			<< 	"4) Bogo Sort (Use only with small arrays)\n"
			<< 	"Enter Choice: ";
}
int main()
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	int choice;
 	//printMenu();
	bool quit=false;
	//std::cin >> choice;
	int size;
	int lowerBound;
	int upperBound;
	char yn;
	while(!quit)
	{
		printMenu();
		std::cin>>choice;
		std::cout << "Input a size for the random array\n";
		std::cin >> size;
		int* arr = new int[size];
		std::cout << "Input a lower bound on the range of random numbers: \n";
		std::cin >> lowerBound;
		std::cout << "Input a upper bound on the range of random numbers: \n";
		std::cin >> upperBound;
		std::default_random_engine generator(time(nullptr));
		std::uniform_int_distribution<int> distribution(lowerBound,upperBound);
		for(int i=0; i<size;i++)
		{
			arr[i]=distribution(generator);
		}
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
		if(choice==1)
		{
			std::cout << "Sorting with bubble sort...\n";
			start = std::chrono::system_clock::now();
			Sorts<int>::bubbleSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		else if(choice==2)
		{	
			std::cout << "Sorting with insertion sort\n";
			start = std::chrono::system_clock::now();
			Sorts<int>::insertionSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		else if(choice==3)
		{
			std::cout << "Sorting with selection sort\n";
			start = std::chrono::system_clock::now();
			Sorts<int>::selectionSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		else if(choice==4)
		{
			std::cout << "Be sure to use a small number or this may take a while\n";
			start = std::chrono::system_clock::now();
			Sorts<int>::bogoSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		elapsed = (end-start);
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

		std::cout << size << " numbers were sorted in " << elapsed.count() << " seconds.";		
		delete arr;
		std::cout << "Do you want to quit?(y/n)";
		std::cin>>yn;
		if(yn=='y')
		{
			quit=true;
		}
		
	}
	return 0;
}
