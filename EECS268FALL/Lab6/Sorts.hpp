 /**
*	@file:		Sorts.hpp
*	@author:	Austin Bailey
*	@date:		*3/27/2015
*	@purpose:	Implementaion file for sorts class
*/ 
#include <random>
#include <ctime>
#include <cassert>
#include <functional>
#include <chrono>
template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
	T tempt = arr[0]; 
	for(int i = 0; i<size; i++)
	{
		for(int j=0; j<(size-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				tempt=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tempt;
			}
		}
	}
	assert( Sorts<T>::isSorted(arr,size));
}
template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
	std::default_random_engine generator(time(nullptr));

	while(true)
	{
		Sorts<T>::shuffle(arr, size, generator);
		if(isSorted(arr,size))
		{
			assert( Sorts<T>::isSorted(arr,size));
			return;
		}
	}
	assert( Sorts<T>::isSorted(arr,size));
}
template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	T temp;
	int j;
	for(int i=1; i<size; i++)
	{
		j = i;
		while((j>0)&&(arr[j-1]>arr[j]))
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
		}
	}
	assert( Sorts<T>::isSorted(arr,size));

}
template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	T tempt;
	int smallestIndex=0;
	for(int i=0; i<size; i++)
	{
		T smallest=arr[i];
		for(int j=i; j<size; j++)
		{
			if(smallest>arr[j])
			{
				smallest=arr[j];
				smallestIndex=j;
			}
		}
		tempt=arr[i];
		arr[i]=smallest;
		arr[smallestIndex]=tempt;
	}
//	assert( Sorts<T>::isSorted(arr,size));
}
template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		if(arr[i]>arr[i+1])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
	int* arr = new int[size];
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min,max);
	for(int i=0; i<size;i++)
	{
	arr[i]=distribution(generator);
	}
	return arr;
}


template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	start = std::chrono::system_clock::now();
	sort(arr,size);
	end = std::chrono::system_clock::now();
	elapsed=end-start;
	return elapsed.count();	
}


template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
	std::uniform_int_distribution<int> distribution(0,size-1);
	T tempt = arr[0];
	int rand;
	for(int i=0; i<size; i++)
	{
		rand=distribution(generator);
		tempt= arr[i];
		arr[i]=arr[rand];
		arr[rand]=tempt;
	}
}

