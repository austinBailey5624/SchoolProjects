 /**
*	@file: 		PreconditionViolationException.cpp
*	@author:	Austin Bailey
*	@date:		2.27.2015
*	@purpose:	Implementation file for the PreconditionViolationException class
*/
#include <stdexcept>
#include "PVE.h"
PVE::PVE(const char* message):std::runtime_error(message)
{

}
