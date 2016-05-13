/**
*	@file:		MazeWalker.h
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: Header File for the Maze Walker Class
**/ 
#ifndef MAZEWALKER_H
#define MAZEWALKER_H
#include "Position.h"
class MazeWalker
{
	public:
		MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);
		void walkMaze();

	protected:
		void storeValidMoves();
		void move(Position& p);
		bool isGoalReached()const;
		
		bool m_isDFS;
		char** m_maze;
		bool** m_visited;
		int m_rows, m_cols;
		Position m_curPos;
		Position m_startPos;
};
#endif
