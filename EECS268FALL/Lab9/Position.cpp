/**
*	@file:		Position.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: implementation file for the Position class
**/ 
#include "Position.h"
Position::Position(int row, int col)
{
	this->m_row = row;
	this->m_col = col;
}

int Position::getRow()const
{
	return this->m_row;
}

int Position::getCol()const
{
	return this->m_col;
}
