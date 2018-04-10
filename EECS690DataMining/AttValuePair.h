/*
*   @file:      AttValuePair.h
*   @author:    Austin Bailey
*   @date:      11/18/2017
*/

#ifndef ATTVALUEPAIR_H
#define ATTVALUEPAIR_H

#include <string>
#include <iostream>
#include <fstream>

class AttValuePair
{
    public:
        AttValuePair();
        AttValuePair(std::string attribute, std::string value);
        std::string getAttribute();
        std::string getValue();
        bool getNegate();
        void setAttribute(std::string attribute);
        void setValue(std::string value);
        void setNegate(bool negate);
        void print();
        void printNegation(std::ofstream printer);
        std::string printString();
        bool equals(AttValuePair cantidate);
        bool equalsIgnoreNegation(AttValuePair cantidate);

    private:
        std::string m_attribute;
        std::string m_value;
        bool m_negate;
};
#endif
