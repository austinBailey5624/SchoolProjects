/*
*   @file:      Attribute.h
*   @author:    Austin Bailey
*   @date:      11/13/2017
*/

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <vector>
#include <string>

class Attribute
{
    public:
        Attribute(std::string name);
        ~Attribute();
        bool isNumerical();
        bool isBinary();
        std::string getName();


    private:
        std::string m_name;
//        std::vector<std::string> types;
//        double named;
//        std::string names;
};
#endif
