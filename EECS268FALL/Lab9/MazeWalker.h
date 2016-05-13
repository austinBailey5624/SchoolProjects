/**
*	@file:		MazeWalker.h
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: Header File for the Maze Walker Class
**/ 
#ifndef MAZEWALKER_H
#define MAZEWALKER_H
#include "Position.h"
#include <stack>
#include <queue>
#include <fstream>
enum class Search
{
	DFS,
	BFS
};
class MazeWalker
{
	public:
		MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice);	
		~MazeWalker();
		void walkMaze();
		const int* const* getVisited() const;
		int getVisitedRows() const;
		int getVisitedCols() const;
		const char* const* getMaze() const;
	protected:
		void storeValidMoves();
		void move(Position& p);
		bool isGoalReached()const;
		
		Search m_searchType;
		const char* const* m_maze;
		int** m_visited;
		int m_rows, m_cols;
		Position m_curPos;
		Position m_startPos;

		std::stack<Position> m_moveStack;
		std::queue<Position> m_moveQueue;

		int m_curStep;
};
#endif
