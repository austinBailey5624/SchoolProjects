/**
*   @file:      Rule.h
*   @author:    Austin Bailey
*   @date:      11/18/2017
*/

#ifndef RULE_H
#define RULE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "AttValuePair.h"

class Rule
{
    public:

        Rule(AttValuePair concept);
        void addCondition(AttValuePair condition);
        void addNegCondition(AttValuePair condition);
        void print();
//        void printNegation(std::ofstream printer);
        std::string printString();
        bool casePasses(std::vector<AttValuePair> casei);
        bool containsCondition(AttValuePair condition);
        std::vector<AttValuePair> getConditions();
        AttValuePair getConcept();
        void setConditions(std::vector<AttValuePair> conditions);


    private:
        std::vector<AttValuePair> m_conditions;
        AttValuePair m_concept;
};
#endif
