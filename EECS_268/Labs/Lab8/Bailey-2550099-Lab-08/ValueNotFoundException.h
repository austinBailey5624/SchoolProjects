 /**
*	@file: 		ValueNotFoundException.h
*	@author:	Austin Bailey
*	@date:		2.27.2015
*	@purpose:	Header file for the ValueNotFoundException class
*/ 
#ifndef VALUENOTFOUNDEXCEPTION_H
#define VALUENOTFOUNDEXCEPTION_H
#include <iostream>
#include <stdexcept>
class ValueNotFoundException: public std::runtime_error
{
	public:
		/**
		* @pre: calling the method
		* @post: values are not changed, but message is displayed
		* @return: control is returned to main method
		*/
		ValueNotFoundException(const char* message);
};
#endif
