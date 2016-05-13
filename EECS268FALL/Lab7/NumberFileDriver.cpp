/**
*	@file: 		NumberFileDriver.cpp
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	Implementation file for the NumberFIleDriver class
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
void NumberFileDriver::run(int argc, char** argv)
{
	std::string s1=argv[2];//need stoi
	std::string filename=argv[3];
	int amount=std::stoi(argv[4]);
	int arg5;
	int max;
	if((s1=="-a")&&(argc==5))
	{	
		NumberFileGenerator::ascending(filename,amount);
	}
	else if((s1=="-d")&&(argc==5))
	{
		NumberFileGenerator::descending(argv[3],amount);
	}
	else if((s1=="-s")&&(argc==6))
	{
		arg5=std::stoi(argv[5]);
		NumberFileGenerator::singleValue(argv[3],amount,arg5);
	}
	else if((s1=="-r")&&(argc==7))
	{
		arg5=std::stoi(argv[5]);
		max=std::stoi(argv[6]);
		NumberFileGenerator::random(argv[3],amount,arg5,max);
	}
	else
	{
		printHelpMenu();
	}

}

void NumberFileDriver::printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}
