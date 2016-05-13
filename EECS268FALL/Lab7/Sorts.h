/**
*	@file: 		Sorts.h
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	Header file for sorts class
**/
#ifndef SORTS_H
#define SORTS_H
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
template <typename T>
class Sorts
{
	public:
            
                /**
                 *      @pre: nothing
                 *      @post: an array
                 *      @return: an array of type t randomly created
                 **/
                static T* createTestArray(int size, int low, int high);
                
		/**
		*	@pre: 	An array you need sorted
		*	@post: 	sorts the array
		*	@return:void
		**/
		static void insertionSort(T arr[], int size);
		
                /**
		*	@pre: 	An array you need sorted
		*	@post: 	sorts the array
		*	@return:void
		**/
		static void bubbleSort(T arr[], int size);

		/**
		*	@pre: 	An array you need sorted
		*	@post: 	sorts the array
		*	@return:void
		**/
		static void mergeSort(T arr[], int size);

		/**
		*	@pre: 	An array you need sorted
		*	@post: 	sorts the array
		*	@return:void
		**/
		static void quickSort(T arr[], int size);
                
                /**
                 *      @pre:   an array you need sorted
                 *      @post:  sorts the array
                 *      @return:void
                 */
                static void bogoSort(T arr[], int size);

		/**
		*	@pre: 	An array you need sorted
		*	@post: 	sorts the array
		*	@return:void
		**/
		static void quickSortWithMedian(T arr[],int size);

		/**
		*	@pre: 	An array you need sorted
		*	@post: 	sorts the array
		*	@return:void
		**/
		static void selectionSort(T arr[], int size);

		/**
		*	@pre: 	An array whose sortedness you need to determine
		*	@post: 	Changes nothing
		*	@return:true if sorted in ascending, false else
		**/
		static bool isSorted(T arr[], int size);

		/**
		*	@pre: 	An array you need sorted in a given method
		*	@post: 	sorts the array
		*	@return:the time it took to sort the array using the given mentod
		**/
		static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);

	private:
		/**
		*	@pre: 	Two sorted arrays that need to be merged
		*	@post: 	merges the sorted arrays into a larger sorted array
		*	@return:void
		**/
		static void merge(T* a1, T* a2, int size1, int size2);
		static void quickSortRec(T arr[], int first, int last, bool median);
		static void setMedianPivot(T arr[], int first, int last);
		static int partition(T arr[], int first, int last, bool median);
		static void shuffle(T arr[], int size, std::default_random_engine generator);	
	
};
#include "Sorts.hpp"
#endif
