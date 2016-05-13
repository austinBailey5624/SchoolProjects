/**
*	@file:		PreconditionViolationException.h
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	header file for the PreconditionViolationException class
*/ 
#ifndef PRECONDITIONVIOLATIONEXCEPTION_H
#define PRECONDITIONVIOLATIONEXCEPTION_H
#include <iostream>
#include <stdexcept>
class PreconditionViolationException: public std::runtime_error
{
	public:
		/**
		* @pre: calling the method
		* @post: values are not changed, but message is displayed
		* @return: control is returned to main method
		*/
		PreconditionViolationException(const char* message);
};
#endif 
