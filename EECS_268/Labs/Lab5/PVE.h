/**
*	@file: 		PVE.h
*	@author:	Austin Bailey
*	@date:		2.27.2015
*	@purpose:	Header file for the PreconditionViolationException class
*/ 
#ifndef PVE_H
#define PVE_H
#include <iostream>
#include <stdexcept>
class PVE: public std::runtime_error
{
	public:
		/**
		* @pre: calling the method
		* @post: values are not changed, but message is displayed
		* @return: control is returned to main method
		*/
		PVE(const char* message);
};
#endif
