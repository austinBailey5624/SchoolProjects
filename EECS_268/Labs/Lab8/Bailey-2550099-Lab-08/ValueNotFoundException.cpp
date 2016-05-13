/**
*	@file: 		ValueNotFoundException.cpp
*	@author:	Austin Bailey
*	@date:		3.16.2015
*	@purpose:	Implementation file for the ValueNotFoundException class
*/
#include <stdexcept>
#include "ValueNotFoundException.h"
ValueNotFoundException::ValueNotFoundException(const char* message):std::runtime_error(message)
{

}
