/**
*   @file:      AttValuePair.c++
*   @author:    Austin Bailey
*   @date:      11/18/2017
*/
#include "AttValuePair.h"

AttValuePair::AttValuePair()
{

}

AttValuePair::AttValuePair(std::string attribute, std::string value)
{
    m_attribute=attribute;
    m_value = value;
    m_negate = false;
}

std::string AttValuePair::getAttribute()
{
    return m_attribute;
}

std::string AttValuePair::getValue()
{
    return m_value;
}

bool AttValuePair::getNegate()
{
    return m_negate;
}

void AttValuePair::setAttribute(std::string attribute)
{
    m_attribute = attribute;
}

void AttValuePair::setValue(std::string value)
{
    m_value = value;
}

void AttValuePair::setNegate(bool negate)
{
    m_negate = negate;
}

void AttValuePair::print()
{
    if(m_negate)
    {
        std::cout << "(" << m_attribute << ", not " << m_value << ") ";
        return;
    }
    std::cout << "("<< m_attribute << ", " << m_value << ") ";
}

void AttValuePair::printNegation(std::ofstream printer)
{
    if(m_negate)
    {
        printer << "(" << m_attribute << ", not " << m_value << ") ";
        return;
    }
    printer << "(" << m_attribute << ", " << m_value << ") ";
}

std::string AttValuePair::printString()
{
    std::string result;
    if(m_negate)
    {
        result += "(";
        result += m_attribute;
        result += ", not ";
        result += m_value;
        result += ") ";
        return result;
    }
    result += "(";
    result += m_attribute;
    result += ", ";
    result += m_value;
    result += ")";
    return result;
}

bool AttValuePair::equals(AttValuePair cantidate)
{
    if(!m_attribute.compare(cantidate.getAttribute())==0)
    {
        return false;
    }
    if(!m_value.compare(cantidate.getValue())==0)
    {
        return false;
    }
    if(!m_negate==cantidate.getNegate())
    {
        return false;
    }
    return true;
}

bool AttValuePair::equalsIgnoreNegation(AttValuePair cantidate)
{
    if(!m_attribute.compare(cantidate.getAttribute())==0)
    {
        return false;
    }
    if(!m_value.compare(cantidate.getValue())==0)
    {
        return false;
    }
    return true;
}
