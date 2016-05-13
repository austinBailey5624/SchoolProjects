/**
*	@file:		main.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: space for the implementation of the MazeReader/Walker classes
**/
#include <iostream>
#include "MazeReader.h"
#include "MazeWalker.h"
#include "Test.h"
int main(int argc,char** argv)
{
	if(argc>3||argc<2)
	{
		std::cout << "There are an improper number of arguments, three needed:\n1) program name 2)file name, 3) search option (either -dfs or -bfs), or two needed\n1)program Name, 2)-test\n";
	return 0;
	}
	if(argc==3)
	{
		std::string fileName = argv[1];
		std::string searchOption=argv[2];
		Search mySearch;
		if(searchOption=="-dfs")
		{
			mySearch=Search::DFS;
		}
		else
		{
			mySearch=Search::BFS;
		}
		try
		{
			MazeReader* reader=new MazeReader(fileName);
			const char* const* maze = reader->getMaze(); 
			MazeWalker* walker = new MazeWalker(maze,reader->getStartRow(),reader->getStartCol(),reader->getRows(),reader->getCols(), mySearch);
		}
		catch(std::exception e)
		{
			std::cout << e.what();
		}
		return 0;
	}
	else if(argc==2)
	{
		std::string testChoice = argv[1];//convert from char* to std::string
		if(testChoice.compare("-test")==0)
		{
			Test myTester; //declares a test instance
			myTester.runTests();
		}
		else
		{
			std::cout << "Sorry we couldn't understand your input try 2)-test";
		}
		return 0;
	}
	else
	{
		std::cout << "Sorry, we couldn't understand your input, try 1)Program name, 2)-test\n";
	}
}
/*
	creating a 5*6 matrix
	int** m_visted = nullptr
	m_visited=new int*[5];
	for(int i=0; i<5; i++)
	{
		m_visited[i]=new int[6];
	}
*/
