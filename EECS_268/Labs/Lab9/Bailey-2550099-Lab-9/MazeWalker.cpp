/**
*	@file:		MazeWalker.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: implementation File for the Maze Walker Class
**/ 
#include <stack>
#include <queue>
#include "MazeWalker.h"
MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs)
	:m_curPos(startRow,startCol),m_startPos(startRow,startCol),m_isDFS(dfs)
{
//	m_maze = mazePtr;
//	m_rows = rows;
//	m_cols = cols;
//	m_transversed = new bool*[m_rows];
//	//makes the arrays of the array
//	for(int i = 0; i<m_rows; i++)
//	{
//		m_transversed[i] = new bool[m_cols];
//	}
//	//populates the boolean array
//	for(int i=0; i<m_rows; i++)
//	{
//		for(int j = 0; j < m_cols; j++)
//		{
//			m_transversed[i][j] = false;
//		}
//	}
}

void MazeWalker::walkMaze()
{

}

void MazeWalker::storeValidMoves()
{
//	Position* up = new Position(m_curPos->getRow()-1, m_curPos->getCol());
//	Position* right = new Position(m_curPos->getRow(), m_curPos->getCol()+1);
//	Position* down = new Position(m_curPos->getRow()+1, m_curPos->getCol());
//	Position* left = new Position(m_curPos->getRow(), m_curPos->getCol()-1);

}

void MazeWalker::move(Position& p)
{

}

bool MazeWalker::isGoalReached()const
{
return true;
}
