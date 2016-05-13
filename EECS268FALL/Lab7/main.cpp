/**
*	@file: 		main.cpp
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	space for the timing and execution of sorts
**/
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"
#include "SortDriver.h"
#include "Test.h"
int main(int argc, char** argv)
{
	std::string mode = argv[1];
	if(mode== "-create")
	{
		NumberFileDriver::run(argc, argv);
	}
	else if(mode== "-sort")
	{
		SortDriver::run(argc,argv);
	}
	else if(mode== "-test")
	{
		Test myTester(std::cout);
		myTester.runTests();
	}
	else
	{
		std::cout << "Sorry, We don't know what you mean! please restart the program and give us a -create or -sort argument after the program call!!";
	}
	return 0;
}	
