/**
*	@file: 		SortDriver.cpp
*	@author:	Austin Bailey
*	@date:		4/3/2015
*	@purpose:	implementation file for Sort Driver Class
**/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <functional>
#include "Sorts.h"
#include "SortDriver.h"
#include "NumberFileGenerator.h"
void SortDriver::run(int argc, char** argv)
{
	
	std::string type = argv[2];
	std::string inputFileName=argv[3];
	if(SortDriver::areParametersValid(type,inputFileName))
	{
		double time;
		std::ifstream inputFile(inputFileName);
		std::string outputFileName = argv[4];
		int size = SortDriver::getFileCount(inputFile);
		int* arr = SortDriver::createArray(inputFile, size);
		if((type=="-bubble")&&(argc==5))
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
			myOutputFile << "Bubble Sort sort " << size << " numbers in " << time << " seconds.\n";
			myOutputFile.close();
		}
		else if((type=="-selection")&&(argc==5))
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
			myOutputFile << "Selection Sort sort " << size << " numbers in " << time << " seconds.\n";
			myOutputFile.close();
		}
		else if((type=="-insertion")&&(argc==5))
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);
			myOutputFile << "Insertion Sort sort " << size << " numbers in " << time << " seconds.\n";
			myOutputFile.close();
		}
		else if((type=="-quick")&&(argc==5))	
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, size);
			myOutputFile << "Quick Sort sort " << size << " numbers in " << time << " seconds.\n";
			myOutputFile.close();
		}
		else if((type=="-quick3")&&(argc==5))
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, arr, size);
			myOutputFile << "Quick Sort (with median) sort " << size << " numbers in " << time << " seconds.\n";
			myOutputFile.close();
		}
		else if((type=="-merge")&&(argc==5))
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, size);
			myOutputFile << "Merge Sort sort " << size << " numbers in " << time << " seconds.\n";
			myOutputFile.close();
		}
		else if((type=="-all")&&(argc==5))
		{
			std::ofstream myOutputFile(outputFileName);
			time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
			myOutputFile << "Bubble Sort sort " << size << " numbers in " << time << " seconds.\n";			
			time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
			myOutputFile << "Selection Sort sort " << size << " numbers in " << time << " seconds.\n";			
			time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, arr, size);
			myOutputFile << "Insertion Sort sort " << size << " numbers in " << time << " seconds.\n";
			time = Sorts<int>::sortTimer(Sorts<int>::quickSort, arr, size);
			myOutputFile << "Quick Sort sort " << size << " numbers in " << time << " seconds.\n";
			time = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, arr, size);
			myOutputFile << "Quick Sort (median) sort " << size << "numbers in " << time << " seconds.\n";
			time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, arr, size);
			myOutputFile << "Merge Sort sort " << size << " numbers in " << time << " seconds.\n";
		}
	}
	else
	{
		SortDriver::printHelpMenu();
	}
}
void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}
bool SortDriver::isFileAccessible(std::string fileName)
{
	std::ifstream file(fileName);
	if(file.good())
	{
		file.close();
		return true;
	}
	file.close();
	return false;	
}
bool SortDriver::isSortValid(std::string sortParameter)
{
	if((sortParameter=="-bubble")||(sortParameter=="-selection")||(sortParameter=="-insertion")||(sortParameter=="-quick")||(sortParameter=="-quick3")||(sortParameter=="-merge")||(sortParameter=="-all"))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	return (SortDriver::isFileAccessible(inputFileName)&&SortDriver::isSortValid(sortName));
}
int SortDriver::getFileCount(std::ifstream& inputFile)
{
	int count;
	inputFile >> count;
	return count;
}
int* SortDriver::createArray(std::ifstream& inputFile, int size)
{
	int* arr = new int[size];
	for(int i=0; i<size; i++)
	{
		inputFile >> arr[i];
	}
	inputFile.close();
	return arr;
}
