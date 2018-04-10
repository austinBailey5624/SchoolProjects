/**
*   @file:      Attribute.c++
*   @author:    Austin Bailey
*   @date:      11/13/2017
*/
#include "Attribute.h"

Attribute::Attribute(std::string name)
{
    m_name = name;
}

Attribute::~Attribute()
{

}

std::string Attribute::getName()
{
    return m_name;
}

bool Attribute::isNumerical()
{
    return true;
}

bool Attribute::isBinary()
{
    return true;
}
