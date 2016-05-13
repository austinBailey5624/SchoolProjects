/**
*	@file: 		NumberFileDriver.h
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	header file for the NumberFileDriver class
**/
#include <string>
#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H
class NumberFileDriver
{
	public:
		static void run(int argc, char** argv);
		static void printHelpMenu();
	private:
		static bool isValidOption(std::string option);
};
#endif
