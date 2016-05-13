/**
*	@file:		MazeCreationException.cpp
*	@author:	Austin Bailey
*	@date:		4/17/2015
*	@purpose: implementation file for the MazeCreationException Class
**/
#include <stdexcept>
#include "MazeCreationException.h"
MazeCreationException::MazeCreationException(const char* message):std::runtime_error(message)
{

}
