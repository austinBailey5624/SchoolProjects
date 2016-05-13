/**
*	@file: 		NumberFileGenerator.cpp
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	implementation file for the NumberFileGenerator class
**/
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <ctime>
#include <cassert>
#include <fstream>
#include <random>
#include "NumberFileGenerator.h"
void NumberFileGenerator::ascending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);
	myOutputFile << amount << "\n";
	for(int i=0; i<amount; i++)
	{
		myOutputFile<< i << "\n";
	}
	myOutputFile.close();
}
void NumberFileGenerator::descending(std::string fileName, int amount)
{
	std::ofstream myOutputFile(fileName);
	myOutputFile<< amount << "\n";
	for(int i=amount; i>=0; i--)
	{
		myOutputFile<<i<<"\n";
	}
	myOutputFile.close();
}
void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
	std::ofstream myOutputFile(fileName);
	myOutputFile<< amount << "\n";
	for(int i=0; i<amount; i++)
	{
		myOutputFile<<value<<"\n";
	}
	myOutputFile.close();
}
void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min,max);
	std::ofstream myOutputFile(fileName);
	int randomNumber;
	myOutputFile<<amount<<"\n";
	for(int i=0; i<amount; i++)
	{
		randomNumber=distribution(generator);
		myOutputFile<<randomNumber<<"\n";
	}
	myOutputFile.close();
}
