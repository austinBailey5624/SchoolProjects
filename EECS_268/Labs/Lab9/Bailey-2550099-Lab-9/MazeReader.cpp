/**
*	@file:		MazeReader.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: implementation file for the MazeReader class
**/
#include "MazeReader.h"
#include "MazeCreationException.h"
#include <stdexcept>
#include <string>
#include <fstream>
MazeReader::MazeReader(std::string fileName) throw (MazeCreationException)  
{
	std::ifstream file(fileName);
	if( file.good())
	{
		m_maze = new char*[m_rows];
		for(int i=0; i<m_cols; i++)
		{
 			m_maze[i]=new char[m_cols];
		}
		file >> m_rows;
		file >> m_cols;
		file >> m_startCol;
		file >> m_startRow;
		if((m_rows<1)||(m_cols<1)||(m_startCol<0)||(m_startCol>m_cols)||(m_startRow>m_rows)||(m_startRow<0))
		{
			throw(MazeCreationException("The File is bad"));		
		}
		for(int i=0;i<m_rows;i++)
		{
			for(int j=0;j<m_cols;j++)
    			{
                file >>m_maze[i][j];
    			}
		}
	}
	else
	{
		throw(MazeCreationException("File cannot be accessed"));
	}
}

MazeReader::~MazeReader()
{
	for(int i=0; i<m_cols; i++)
	{
		delete[] m_maze[i];
	}
	delete[] m_maze;
}

char** MazeReader::getMaze() const
{
	return m_maze;
}

int MazeReader::getCols() const
{
	return m_cols;
}

int MazeReader::getRows() const
{
	return m_rows;
}

int MazeReader::getStartCol() const
{
	return m_startCol;
}

int MazeReader::getStartRow() const
{
	return m_startRow;
}

void MazeReader::readMaze() throw (MazeCreationException)
{

}

