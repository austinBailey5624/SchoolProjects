/**
*	@file: 		main.cpp
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	space for the timing and execution of sorts
**/
#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H
class NumberFileGenerator
{
	public:
	static void ascending(std::string fileName, int amount);
	static void descending(std::string fileName, int amount);
	static void random(std::string fileName, int amount, int min, int max);
	static void singleValue(std::string fileName, int amount, int value);
};
#endif
