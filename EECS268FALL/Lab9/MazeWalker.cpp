/**
*	@file:		MazeWalker.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: implementation File for the Maze Walker Class
**/ 
#include <stack>
#include <queue>
#include "MazeWalker.h"
MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice)
	:m_curPos(startRow,startCol),m_startPos(startRow,startCol),m_searchType(searchChoice)
{
	m_curStep=2;
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;
	m_visited = new int*[m_rows];
	//makes the arrays of the array
//	for(int i = 0; i<m_rows; i++)
//	{
//		m_visited[i] = new int[m_cols];
//	}
//	//populates the int array with zeroes
	for(int i=0; i<m_rows; i++)
	{
		m_visited[i] = new int[m_cols];
		for(int j = 0; j < m_cols; j++)
		{
			m_visited[i][j] = 0;
		}
	}
	m_visited[startRow][startCol]=1;
}

MazeWalker::~MazeWalker()
{
	for(int i=0;i<m_rows; i++)
	{
		delete[] m_visited[i];
	}
	delete[] m_visited;
}

void MazeWalker::walkMaze()
{
	if(m_searchType==Search::DFS)
	{
		storeValidMoves();
		while(!((isGoalReached())&&(!m_moveStack.empty())))
		{
			if((m_moveStack.top().getRow()>0)&&(m_moveStack.top().getRow()<getVisitedRows()+1)&&(m_moveStack.top().getCol()>0)&&(m_moveStack.top().getCol()>getVisitedCols()+1))//ensures that it is in maze boundaries
			{
				if(m_maze[m_moveStack.top().getRow()][m_moveStack.top().getCol()]=='P')
				{
					move(m_moveStack.top());
				}
			}
			m_moveStack.pop();
		}
	}
	else if(m_searchType==Search::BFS)
	{
		storeValidMoves();
		while(!(isGoalReached()&&!m_moveQueue.empty()))
		{
			if((m_moveQueue.front().getRow()>0)&&(m_moveQueue.front().getRow()<getVisitedRows()+1)&&(m_moveQueue.front().getCol()>0)&&(m_moveQueue.front().getCol()>getVisitedCols()+1))
			{
				if(m_maze[m_moveQueue.front().getRow()][m_moveQueue.front().getCol()]=='P')
				{
					move(m_moveQueue.front());
				}
			}
			m_moveQueue.pop();
		}
	}
}

const int* const* MazeWalker::getVisited()const
{
	return this->m_visited;
}


int MazeWalker::getVisitedRows()const
{
	return this->m_rows;
}

int MazeWalker::getVisitedCols()const
{
	return this->m_cols;
}

const char* const* MazeWalker::getMaze()const
{
	return m_maze;
}
void MazeWalker::storeValidMoves()
{
//	Position* up = new Position(m_curPos->getRow()-1, m_curPos->getCol());
//	Position* right = new Position(m_curPos->getRow(), m_curPos->getCol()+1);
//	Position* down = new Position(m_curPos->getRow()+1, m_curPos->getCol());
//	Position* left = new Position(m_curPos->getRow(), m_curPos->getCol()-1);
	Position up= Position(m_curPos.getRow()-1, m_curPos.getCol());
	Position right= Position(m_curPos.getRow(), m_curPos.getCol()+1);
	Position down = Position(m_curPos.getRow()+1, m_curPos.getCol());
	Position left = Position(m_curPos.getRow(), m_curPos.getCol()-1);
	if(m_searchType==Search::BFS)
	{
		m_moveQueue.push(up);
		m_moveQueue.push(right);
		m_moveQueue.push(down);
		m_moveQueue.push(left);
		return;
	}
	else if(m_searchType==Search::DFS)
	{
		m_moveStack.push(up);
		m_moveStack.push(right);
		m_moveStack.push(down);
		m_moveStack.push(left);
		return;
	}
}

void MazeWalker::move(Position& p)
{
	m_curPos=p;
	m_visited[m_curPos.getRow()][m_curPos.getCol()]=m_curStep;
	m_curStep++;
}

bool MazeWalker::isGoalReached()const
{
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E')
	{
		return true;
	}
	return false;
}
