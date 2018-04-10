/**
*   @file:      Rule.h
*   @author:    Austin Bailey
*   @date:      11/18/2017
*/

#include "Rule.h"

Rule::Rule(AttValuePair concept)
{
    m_concept = concept;
}

void Rule::addCondition(AttValuePair condition)
{
    //checks that the condition is not already in the rule
    //condition.setNegate(false);
    for(unsigned int i = 0; i< m_conditions.size(); i++)
    {
        if(m_conditions[i].equals(condition))
        {
            return;
        }
    }
    m_conditions.push_back(condition);
}

void Rule::addNegCondition(AttValuePair condition)
{
    bool debug = false;
    condition.setNegate(true);
    for(unsigned int i = 0; i< m_conditions.size(); i++)
    {
        if(debug)
        {
            std::cout << "m_conditions[i]: ";
            m_conditions[i].print();
            std::cout << "\n";
            std::cout << "condition:       ";
            condition.print();
            std::cout << "\n";
        }
        if(m_conditions[i].equals(condition))
        {
            if(debug)
            {
                std::cout << "declared equal\n";
            }
            return;
        }
    }

    m_conditions.push_back(condition);
}

void Rule::print()
{
    for(unsigned int i = 0; i< m_conditions.size(); i++)
    {
        m_conditions[i].print();
        if(i<m_conditions.size()-1)
        {
            std::cout << " & ";
        }
    }
    std::cout << " -> ";
    m_concept.print();
}

// void Rule::printNegation(std::ofstream printer)
// {
//     for(unsigned int i = 0; i< m_conditions.size(); i++)
//     {
//         m_conditions[i].printNegation(printer);
//         if(i<m_conditions.size()-1)
//         {
//             printer << " & ";
//         }
//     }
//     printer << " -> ";
//     m_concept.printNegation(printer);
// }

std::string Rule::printString()
{
    std::string result;
    for(unsigned int i = 0; i< m_conditions.size(); i++)
    {
        result += m_conditions[i].printString();
        if(i<m_conditions.size()-1)
        {
            result += " & ";
        }
    }
    result += " -> ";
    result += m_concept.printString();
    return result;
}

bool Rule::casePasses(std::vector<AttValuePair> casei)
{
    //for each AttValuePair in m_conditions
    for(unsigned int i=0; i<m_conditions.size(); i++)
    {
        for(unsigned int j = 0; j<casei.size(); j++)
        {
            //if they have the same attribute
            if(m_conditions[i].getAttribute().compare(casei[j].getAttribute())==0)
            {
                //if they have the same attribute with different values
                if(m_conditions[i].getNegate()==false)
                {
                    if(m_conditions[i].getValue().compare(casei[j].getValue())!=0)
                    {
                        return false;
                    }
                }
                else//if they have the same attribute with the same values and were negating
                {
                    if(m_conditions[i].getValue().compare(casei[j].getValue())==0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Rule::containsCondition(AttValuePair condition)
{
//    std::cout << "checking ";
//    condition.print();
//    std::cout << "against: ";
    bool debug = false;
    for(unsigned int i = 0; i<m_conditions.size(); i++)
    {
        if(debug)
        {
            m_conditions[i].print();
        }
        if(m_conditions[i].equals(condition))
        {
//            std::cout << "\n\n\nPASS\n\n\n";
            return true;
        }
    }
    return false;
}

std::vector<AttValuePair> Rule::getConditions()
{
    return m_conditions;
}

AttValuePair Rule::getConcept()
{
    return m_concept;
}

void Rule::setConditions(std::vector<AttValuePair> conditions)
{
    m_conditions = conditions;
}
