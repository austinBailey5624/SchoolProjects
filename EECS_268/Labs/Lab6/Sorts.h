 /**
*	@file:		Sorts.h
*	@author:	Austin Bailey
*	@date:		*3/27/2015
*	@purpose:	Header file for sorts class
*/
#ifndef SORTS_H
#define SORTS_H


template <typename T>
class Sorts
{
	public:

		/**
		*	@pre: an array you want sorted
		*	@post: a sorted array
		* 	@return:void
		**/
		static void bubbleSort(T arr[], int size);

		/**
		*	@pre: an array you want sorted
		*	@post: a sorted array
		* 	@return:void
		**/
		static void bogoSort(T arr[], int size);

		/**
		*	@pre: an array you want sorted
		*	@post: a sorted array
		* 	@return:void
		**/
		static void insertionSort(T arr[], int size);

		/**
		*	@pre: an array you want sorted
		*	@post: a sorted array
		* 	@return:void
		**/
		static void selectionSort(T arr[], int size);

		/**
		*	@pre: an array you think is sorted
		*	@post: does not change arguments
		*	@return:true if sorted, false else
		**/
		static bool isSorted(T arr[], int size);

	private:
		/**
		*	@pre: an array you want shuffled
		*	@post: a shuffled array
		*	@return: void
		**/
		static void shuffle(T arr[], int size, std::default_random_engine& generator);
};
#include "Sorts.hpp"
#endif
