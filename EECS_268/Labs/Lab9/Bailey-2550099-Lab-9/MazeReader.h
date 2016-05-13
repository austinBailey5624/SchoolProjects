/**
*	@file:		MazeReader.h
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: Header File for the Maze Reader Class
**/
#ifndef MAZEREADER_H
#define MAZEREADER_H
#include <string>
#include "MazeCreationException.h"
class MazeReader
{
	public:
		MazeReader(std::string fileName) throw (MazeCreationException);
		~MazeReader();
		char** getMaze() const;
		int getCols() const;
		int getRows() const;
		int getStartCol() const;
		int getStartRow() const;

	protected:
		void readMaze() throw (MazeCreationException);

	private:
		char** m_maze;
		int m_cols;
		int m_rows;
		int m_startCol;
		int m_startRow;				
};
#endif
