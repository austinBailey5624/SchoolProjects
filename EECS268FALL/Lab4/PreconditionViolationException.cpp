/**
*	@file:		PreconditionViolationException.cpp
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	implementation file for the PreconditionViolationException class
*/  
#include <stdexcept>
#include "PreconditionViolationException.h"
PreconditionViolationException::PreconditionViolationException(const char* message):std::runtime_error(message)
{

}
