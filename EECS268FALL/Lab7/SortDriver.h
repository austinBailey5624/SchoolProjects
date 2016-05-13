/**
*	@file: 		SortDriver.h
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	header file for Sort Driver class
**/
#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <string>
class SortDriver
{
	public:
		/**
		*	@pre: 	correct arguments argc and argv, checked by main
		*	@post: 	executes subprogram, creating arrays, sorting them, etc
		*	@return:void
		**/
		static void run(int argc, char** argv);

		/**
		*	@pre: 	need for help menu
		*	@post: 	writes help menu to console
		*	@return:void
		**/
		static void printHelpMenu();
	private:
		//checks if file exits
		static bool isFileAccessible(std::string fileName);
		//calls -bubble or -sort
		static bool isSortValid(std::string sortParameter);
		//calls both is File Accessible
		static bool areParametersValid(std::string sortName, std::string inputFileName);
		static int getFileCount(std::ifstream& inputFile);
		static int* createArray(std::ifstream& inputFile, int size);
		static void copyArray(int original[], int copy[], int size);
};
#endif
