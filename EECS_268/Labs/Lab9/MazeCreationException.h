/**
*	@file:		MazeCreationException.h
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: header file for the MazeCreationException Class
**/
#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <iostream>
#include <stdexcept>
class MazeCreationException: public std::runtime_error
{
	public:
		MazeCreationException(const char* message);
};
#endif
