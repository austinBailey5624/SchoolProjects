/**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: space for the implementation of the MazeReader/Walker classes
**/
#include <iostream>
#include "MazeReader.h"
#include "MazeWalker.h"
int main(int argc,char** argv)
{
	if(argc!=3)
	{
		std::cout << "There are an improper number of arguments, three needed:\n1) program name 2)file name, 3) search option (either -dfs or -bfs)";
	return 0;
	}
	std::string fileName = argv[1];
	std::string searchOption=argv[2];
	bool searchOptionBool=false;
	if(searchOption=="-dfs")
	{
		searchOptionBool=true;
	}
	try
	{
		MazeReader* reader=new MazeReader(fileName);
		char** maze = reader->getMaze(); 
		MazeWalker* walker = new MazeWalker(maze,reader->getStartRow(),reader->getStartCol(),reader->getRows(),reader->getCols(), searchOptionBool);
	}
	catch(std::exception e)
	{
		std::cout << e.what();
	}
	return 0;
}
