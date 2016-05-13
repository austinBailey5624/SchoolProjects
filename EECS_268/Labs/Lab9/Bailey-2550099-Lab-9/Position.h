/**
*	@file:		Position.h
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: 	Header file for the position class
**/ 
#ifndef POSITION_H
#define POSITION_H
class Position
{
	public:
		Position(int row, int col);
		int getRow() const;
		int getCol() const;

	private:
		int m_row;
		int m_col;
};
#endif
