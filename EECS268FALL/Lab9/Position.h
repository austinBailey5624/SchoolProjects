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
		/*
		*	pre:	none
		*	post:	constructs a position with row=int and row=col
		*	return: none, constructor
		*/
		Position(int row, int col);

		/*
		*	pre:		none
		*	post:		const
		*	return:		int, value of m_row
		*/
		int getRow() const;

		/*
		*	pre:		none
		*	post:		const
		*	return:		int, value of m_col
		*/
		int getCol() const;

	private:
		int m_row;
		int m_col;
};
#endif
