/*
*   @File:      main.c++
*   @Author:    Austin Bailey
*   @Date:      11/13/2017
*   @Purpose:   Preform AQ algorithm on a given data set
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Attribute.h"
#include "AttValuePair.h"
#include "Rule.h"

// std::vector<Rule> combineRules2(Rule first, Rule second)
// {
//
// }

void printAttValues(std::vector<std::vector<AttValuePair>> pairs)
{
    for(unsigned int i = 0; i< pairs.size(); i++)
    {
        for(unsigned int j = 0; j<pairs[i].size(); j++)
        {
            pairs[i][j].print();
        }
        std::cout << "\n";
    }
}

void printAttValuePairLine(std::vector<AttValuePair> pairs)
{
    for(unsigned int i = 0; i< pairs.size(); i++)
    {
        pairs[i].print();
    }
    std::cout << "\n";
}

std::vector<Rule> combineRuleVecs(std::vector<Rule> first, std::vector<Rule> second)
{
    for(unsigned int i = 0;i<second.size(); i++)
    {
        first.push_back(second[i]);
    }
    return first;
}

bool containsAttValue(std::vector<AttValuePair> vec, AttValuePair p)
{

    for(unsigned int i = 0; i<vec.size(); i++)
    {
        if(vec[i].equals(p))
        {
            return true;
        }
    }
    return false;
}

int containsAttValueIndex(std::vector<AttValuePair> vec, AttValuePair p)
{
//    std::cout << "52\n";
    // std::cout << "comparing:";
    // printAttValuePairLine(vec);
    // std::cout << "\nto: ";
    // p.print();
    for(unsigned int i = 0; i<vec.size(); i++)
    {
        if(vec[i].equalsIgnoreNegation(p))
        {
            return i;
        }
    }
//    std::cout << "60\n";
    return -1;
}

std::vector<Rule> reduceConcept(std::vector<Rule> set)
{
    std::vector<Rule> result;
    std::vector<AttValuePair> allAttValuePairs;
    unsigned int numMatches = 0;
    bool foundMatch = false;
    std::vector<AttValuePair> unsharedConditions;
    AttValuePair unsharedCondition;
    //for each rule in set
    for(unsigned int i = 0; i < set.size();i++)
    {
        foundMatch=false;
        //for every other rule in the set
        for(unsigned int j=i+1; j< set.size(); j++)
        //for(unsigned int j = 0; j<set.size(); j++)
        {
            numMatches = 0;
            //for every condition in the first rule
            for(unsigned int k = 0; k< set[i].getConditions().size(); k++)
            {
                //if they match conditions
                if(set[j].containsCondition(set[i].getConditions()[k]))
                //if(set[i].containsCondition(set[j].getConditions()[k]))
                {
                    //std::cout << "matched\n";
                    numMatches++;
                    //std::cout << numMatches;
                }
                else
                {
                    unsharedCondition = set[i].getConditions()[k];
                }
            }
            //we want to add the condition to our new condensed rule;
            if(numMatches>=set[i].getConditions().size()-2)
            {
                unsharedConditions.push_back(unsharedCondition);
                foundMatch = true;
                set.erase(set.begin()+j-1);//rule is going to be combined, dont need it anymore
                j--;//decrement so we stay in the same position for the
                //next interation
            }
        }
        //we've found a match and we can condense rules
        if(foundMatch)
        {
            //std::cout << "found match\n";
            for(unsigned int j = 0; j<unsharedConditions.size(); j++)
            {
                set[i].addCondition(unsharedConditions[j]);
            }
            result.push_back(set[i]);
        }
        else//we dont have a match, so rule can't be eliminated
        {
            result.push_back(set[i]);
        }
    }
    return result;
}

//takes all of the Rules in the set and filters them so the result vector
//has only one concept worth of rules
std::vector<Rule> reduceToConcept(std::vector<Rule> set, AttValuePair concept)
{
    std::vector<Rule> result;
    for(unsigned int i = 0; i< set.size(); i++)
    {
        //if they are the same
        if(set[i].getConcept().equals(concept))
        {
            result.push_back(set[i]);
        }
    }
    return reduceConcept(result);
}

std::vector<Rule> reduceRules(std::vector<Rule> set)
{
    std::vector<Rule> result;
    std::vector<AttValuePair> concepts;
    for(unsigned int i = 0; i< set.size(); i++)
    {
        //set[i].print();
        //std::cout << "\n";
        if(!containsAttValue(concepts,set[i].getConcept()))
        {
            concepts.push_back(set[i].getConcept());
        }
    }
    //printAttValuePairLine(concepts);
//    result = combineRuleVecs(reduceToConcept())
    for(unsigned int i = 0; i<concepts.size(); i++)
    {
        result = combineRuleVecs(result, reduceToConcept(set,concepts[i]));
    }
    return result;
}

// bool containsNegation(Rule curRule)
// {
//     for(unsigned int i = 0; i < curRule.getConditions().size(); i++)
//     {
//         if(curRule.getConditions()[i].getNegate())
//         {
//             return true;
//         }
//     }
//     return false;
// }
//
// int numNegations(Rule curRule)
// {
//     int result = 0;
//     for(unsigned int i = 0; i < curRule.getConditions().size(); i++)
//     {
//         if(curRule.getConditions()[i].getNegate())
//         {
//             result++;
//         }
//     }
//     return result;
// }
//
// //returns a vector of all Attribute Value Pairs with the given attribute
// std::vector<AttValuePair> getPairsColumn(std::vector<std::vector<AttValuePair>> allPairs, std::string attribute)
// {
//     for(unsigned int i = 0; i<allPairs.size(); i++)
//     {
//         //if they're the same
//         if(allPairs[i].front().getAttribute().compare(attribute)==0)
//         {
//             return allPairs[i];
//         }
//     }
//     //the following lines should never be accessed and have been
//     //added to make the compiler happy
//     std::vector<AttValuePair> blank;
//     return blank;
// }
//
// std::vector<Rule> eliminateNegationHelper(Rule r,std::vector<std::vector<AttValuePair>> allPairs)
// {
//     std::vector<AttValuePair> relatedAtts;
//     std::vector<Rule> result;
//     Rule* curRule;
//     for(unsigned int i = 0; i < r.getConditions().size();i++)
//     {
//         if(r.getConditions()[i].getNegate()==true)
//         {
//             curRule = new Rule(r.getConcept());
//             relatedAtts = getPairsColumn(allPairs,r.getConditions()[i].getAttribute());
//             //cycle through all not negated attributes to make new rules
//             for(unsigned int j = 0; j<relatedAtts.size(); j++)
//             {
//                 //if we are on the attrubite we need to negate
//                 if(!relatedAtts[j].getAttribute().compare(r.getConditions()[i].getAttribute())==0)
//                 {
//                     //add the other possible attrubites
//                     curRule->addCondition(r.getConditions()[i]);
//                     for(unsigned int k = 0; i<)
//                 }
//
//             }
//         }
//     }
// }
//
// std::vector<Rule> eliminateNegation(std::vector<Rule> set, std::vector<std::vector<AttValuePair>> allPairs)
// {
//     std::vector<Rule> result;
//     int lcv;
//     //for each rule in set
//     for(unsigned int i = 0; i<set.size(); i++)
//     {
//         // while(containsNegation(set[i]))
//         // {
//         //
//         // }
//         lcv = numNegations(set[i]);
//         for(int j = 0; j < lcv; j++)
//         {
//
//         }
//     }
//
// }
std::vector<Rule> eliminateNegationRule(Rule r, std::vector<std::vector<AttValuePair>> allPairs)
{
    //for each concept
    bool debug = false;
    std::vector<Rule> result;
    Rule* ruleptr;
    int temp;
//    std::cout << "255\n";
    //filters conditions present in r out of allPairs
    // std::cout << "before\n";
    // printAttValues(allPairs);
    for(unsigned int i = 0; i< allPairs.size(); i++)
    {
        for(unsigned int j = 0; j<r.getConditions().size(); j++)
        {
//            temp = allPairs[i].containsAttValueIndex(r.getConditions()[j]);
            temp = containsAttValueIndex(allPairs[i],r.getConditions()[j]);
            if(temp!=-1)
            {
                //std::cout << "GOT HERE!!!!\n\n\n";
                //allPairs[i].erase(allPairs[i].begin()+temp-1);
                allPairs[i].erase(allPairs[i].begin() + temp);
            }
            debug = false;
            if(debug)
            {
                std::cout << "i: " << i << "\n";
                std::cout << "j: " << j << "\n";
            }
        }
    }
    // std::cout << "after\n";
    // printAttValues(allPairs);
    //figure out the size of the new vector
    int size = 1;
//    std::vector<int> counts;
//    std::cout << "271\n";
    for(unsigned int i = 0; i< allPairs.size(); i++)
    {
        size *= allPairs[i].size();
//        counts.push_back(0);
    }
    //initialize the new vector
    debug = false;
    if(debug)
    {
        std::cout << "size = " << size << "\n";
    }
    for(int i = 0; i<size; i++)
    {
        ruleptr = new Rule(r.getConcept());
        result.push_back(*(ruleptr));
    }
    //for every new rule
//    std::cout << "283\n";
    /*
    for(unsigned int i = 0; i< allPairs.size(); i++)
    {
        for(unsigned int j = 0; j < allPairs[i].size(); j++)
        {
            result[i].addCondition(allPairs[i][j]);
            counts[j]++;
            if(counts[j]>(int)allPairs[i].size())
            {
                counts[j]=0;
            }
        }
    }*/
    int count[allPairs.size()];

    for(unsigned int j = 0; j< allPairs.size();j++)
    {
        count[j] = 0;
    }
//each rule level
    int curlevel;
    for(unsigned int i = 0; i<result.size(); i++)
    {
        //each concept for each rule level

        for(unsigned int j = 0; j < allPairs.size(); j++)
        {
            //add condition
            result[i].addCondition(allPairs[j][count[j]]);
            //incriment so you add a different one next time
            //if we're at the last index, increment that counts
            //if(j==allPairs.size()-1)
            if(j<=allPairs[j].size())
            {
                count[j]++;
            }
            curlevel = j;
            //overflow logic
            while(count[curlevel]>=(int)allPairs[curlevel].size())
            {
                //if we need to overflow
                //current counts goes to zero
                count[curlevel]=0;
                //if we are already at the beggining, stop
                if(curlevel>=1)
                {
                    //go to the previous level
                    curlevel--;
                    //increment
                    count[curlevel]++;
                }
            }
            // if(counts[j]>(int)allPairs[i].size())
            // {
            //     counts[j] = 0;
            // }
        }
    }

    //erase rules with no conditions
    for(unsigned int i = 0; i< result.size(); i++)
    {
        //if we end up with a rule without conditions
        if(result[i].getConditions().size()==0)
        {
            result.erase(result.begin() + i-1);
            i++;
        }
    }
    return result;
}

std::vector<Rule> eliminateNegation(std::vector<Rule> set, std::vector<std::vector<AttValuePair>> allPairs)
{
    std::vector<Rule> result;
    for(unsigned int i = 0; i< set.size(); i++)
    {
        result = combineRuleVecs(result, eliminateNegationRule(set[i],allPairs));
    }
    return result;
}



bool checkConsistency(std::vector<AttValuePair> first, std::vector<AttValuePair> second)
{
    for(unsigned int i = 0; i< first.size()-1; i++)
    {
        //if they dont match, they can't be inconsistent
        if(!first[i].equals(second[i]))
        {
            return true;
        }
    }
    //to get here, they would have to match in everything but the decision
    if(!first.back().equals(second.back()))
    {
        return false;
    }
    return true;
}

bool isConsistent(std::vector<std::vector<AttValuePair>> cases)
{
    for(unsigned int i = 0; i< cases.size(); i++)
    {//for every case in i
        for(unsigned int j = i+1; j<cases.size(); j++)
        {//for every case folllowing the ith case
            if(!checkConsistency(cases[i],cases[j]))
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<Rule> combineRules(std::vector<Rule> rules, Rule added)
{
    if(rules.empty())
    {
        rules.push_back(added);
        return rules;
    }
    if(added.getConditions().empty())
    {
        return rules;
    }
    std::vector<Rule> result;
    Rule* ruleptr;
    for(unsigned int i = 0; i<rules.size(); i++)//for every rule in rules
    {
        for(unsigned int j = 0; j<added.getConditions().size();j++)
        {
            ruleptr = new Rule(added.getConcept());
            ruleptr->setConditions(rules[i].getConditions());
            ruleptr->addCondition(added.getConditions()[j]);
            result.push_back(*(ruleptr));
        }
        /*
        for(unsigned int j =0; j<rules[i].getConditions().size(); j++)
        {
            if(!rules[i].getConcept().equals(added.getConcept()))
            {
                //if the concepts don't match do nothing
            }
            else
            {

                for(unsigned int k = 0; k<added.getConditions().size(); k++)
                {
                    ruleptr = new Rule(added.getConcept());
                    ruleptr->addCondition(rules[i]);
                    ruleptr->
                }
            }
        }*/
    }
    return result;
}

bool passesRules(std::vector<Rule> rules, std::vector<AttValuePair> casei)
{
    if(rules.empty())
    {
        return true;
    }
    for(unsigned int i =0; i<rules.size(); i++)
    {
        if(!rules[i].casePasses(casei))
        {
            return false;
        }
    }
    return true;
}

std::vector<Rule> appendRuleVectors(std::vector<Rule> head, std::vector<Rule> tail)
{
    // for(unsigned int i = 0; i< tail.size(); i++)
    // {
    //     head.push_back()
    // }
    while(!tail.empty())
    {
        head.push_back(tail.back());
        tail.pop_back();
    }
    return head;
}

void printAllCases(std::vector<std::vector<std::string>> cases)
{
    for(unsigned int i = 0; i<cases.size(); i++)
    {
        for(unsigned int j = 0; j<cases[i].size(); j++)
        {
            std::cout << cases[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void printStringVector(std::vector<std::string> vec)
{
    for(unsigned int i=0; i< vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
}

void printPossibleValues(std::vector<std::vector<std::string>> attValues, std::vector<std::string> attNames)
{
    for(unsigned int i = 0; i < attNames.size(); i++)
    {
        std::cout << attNames[i] << " ";
        for(unsigned int j = 0; j<attValues[i].size(); j++)
        {
            std::cout << attValues[i][j] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<AttValuePair>> generateAttValuePairs(std::vector<std::vector<std::string>> attValues, std::vector<std::string> attNames)
{
    std::vector<std::vector<AttValuePair>> result;
    AttValuePair* singlePtr;
    std::vector<AttValuePair>* rowPtr;
    for(unsigned int i = 0; i< attNames.size(); i++)
    {
        rowPtr = new std::vector<AttValuePair>;
        for(unsigned int j = 0; j<attValues[i].size(); j++)
        {
            singlePtr = new AttValuePair(attNames[i],attValues[i][j]);
            rowPtr->push_back(*(singlePtr));
        }
        result.push_back(*(rowPtr));
    }
    return result;
}

void printAllAttValuePairs(std::vector<std::vector<AttValuePair>> attValues)
{
    for(unsigned int i=0; i< attValues.size(); i++)
    {
        for(unsigned int j=0; j< attValues[i].size(); j++)
        {
            attValues[i][j].print();
        }
        std::cout << "\n";
    }
}



bool vecContainsElement(std::vector<std::string> vec, std::string element)
{
    for(unsigned int i=0; i<vec.size(); i++)
    {
        if (vec[i] == element)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    bool debug = true;
    std::cout << "Enter the name of the textfile you wish to read\n";
    std::string filename;
    std::cin >> filename;
    std::ifstream file(filename);
    int numAttributes = 0;
    char tempc;
    std::string temps;
    //parsing first line
    if(file.good())
    {
        file >> tempc;
        if(!(tempc == '<'))
        {
            std::cout << "bad file, must begin with '<'";
        }
        file >> tempc;
        while(tempc =='a')
        {
            numAttributes++;
            file >> tempc;
        }
        debug=false;
        if(debug)
        {
            std::cout << numAttributes << "     attributes\n";
        }
//        file >> tempc;
        if(!(tempc == 'd'))
        {
            std::cout << "bad file, on first line, 'd' did not folow 'a'";
            std::cout << "tempc = " <<tempc <<"\n";
        }
        file >> tempc;
        if(!(tempc == '>'))
        {
            std::cout << "bad file, first line did not end with '>'";
            std::cout << "tempc = " <<tempc <<"\n";
        }
    }
    else
    {
        std::cout << "file bad, returning\n";
        return 0;
    }
    //parsing second line

    file >> tempc;
    if(!(tempc=='['))
    {
        std::cout << "file bad, expected [ at beginning of second line, instead recieved " << tempc << "\n";
        return 0;
    }
//    std::vector<Attribute*> attVec;
    std::vector<std::string> attVec;
    debug = false;
    for(int i=0; i< numAttributes+1;i++)//plus one since last is decision
    {

        file >>temps;
//        attVec.push_back(new Attribute(temps));
        attVec.push_back(temps);
        if(debug)
        {
            std::cout << "added " << temps << " to attvec\n";
        }
    }
    debug=false;
    if(debug)
    {
        for(unsigned int i=0; i<attVec.size(); i++)
        {
//            std::cout << attVec[i]->getName() << " ";
            std::cout << attVec[i] << " ";
        }
        std::cout << "\n";
    }
    file >> tempc;
    if(!(tempc==']'))
    {
        std::cout << "file bad, expected ] at end of second line, instead recieved " << tempc << "\n";
        return 0;
    }


    int numCases=0;
//    std::vector<std::vector<std::string>> cases;
    std::vector<std::vector<AttValuePair>> cases;
    //reads cases
    debug = false;
//    std::vector<std::string>* casei;
    std::vector<AttValuePair>* casei;
    AttValuePair* tempptr;
    while(file.good())
    {
        casei = new std::vector<AttValuePair>();
        for(unsigned int i = 0; i<attVec.size(); i++)
        {
            file >> temps;
            tempptr = new AttValuePair(attVec[i],temps);
            casei->push_back(*(tempptr));
            //casei->push_back(temps);

            if(debug)
            {
//                std::cout << temps << " ";
                tempptr->print();
            }
        }
        if(debug)
        {
            std::cout << "\n";
        }
        numCases++;
        cases.push_back(*(casei));
    }
    //handle last read (bad)
    cases.pop_back();
    numCases--;


//    debug=true;
    debug=false;
    if(debug)
    {
        std::cout << "\n\n";
//        printAllAttValuePairs(cases);
//        printAllCases(cases);
        std::cout << "\nnumCases: " << numCases << "\n\n";
    }

//holds attribute values- a list of all possible values of a given attribute

    std::vector<std::vector<std::string>> attValues;
    std::vector<std::string>* attValuei;
    for(int i=0; i< numAttributes+1; i++)
    {

        attValuei = new std::vector<std::string>;
        attValues.push_back(*(attValuei));
    }

    debug=false;
    for(int i = 0; i< numAttributes+1; i++)
    {

        for(int j=0; j<numCases; j++)
        {
//            debug=true;
            //std::cout << "182\n";
            // if(debug)
            // {
            //     //std::cout << "attValues[i]:" << attValues[i] << "\n";
            //     std::cout << "cases[j][i] :" << cases[j][i] << "\n";
            // }
            if(!vecContainsElement(attValues[i],cases[j][i].getValue()))
            {
                attValues[i].push_back(cases[j][i].getValue());
            }
            if(debug)
            {
                std::cout << "i:          " << i << "\n";
                std::cout << "j:          " << j << "\n";
                std::cout << "cases[j][i]:" << cases[j][i].getValue() << "\n" << "attValues[i]";
                printStringVector(attValues[i]);
                std::cout << "\n\n";
            }
        }
    }
    debug=false;
    if(debug)
    {
//        std::cout << "192";
        printPossibleValues(attValues, attVec);
    }

    //printAllCases(cases);



    std::vector<std::vector<AttValuePair>> allPairs;

    allPairs = generateAttValuePairs(attValues, attVec);

    debug =false;
    if(debug)
    {
        std::cout << "cases: \n";
        printAllAttValuePairs(cases);
        std::cout << "\n\n Possible Pairs: \n";
        printAllAttValuePairs(allPairs);
    }
    std::vector<AttValuePair> concepts;
    concepts = allPairs.back();

    std::vector<std::vector<AttValuePair>> trueCases;
    std::vector<std::vector<AttValuePair>> falseCases;
    //printAttValuePairLine(concepts);


//Now actually do the AQ algorithm
    // for(unsigned int i = 0; i<concepts.size(); i++)
    // {
    //
    // }
    std::vector<Rule> rules;
    std::vector<Rule> singleSeedRules;
    Rule* ruleptr;
    AttValuePair curConcept;
    debug=false;
    if(debug)
    {
        curConcept = concepts[0];
        for(unsigned int i = 0; i< cases.size(); i++)
        {
            if(cases[i].back().equals(curConcept))
            {
                trueCases.push_back(cases[i]);
            }
            else
            {
                falseCases.push_back(cases[i]);
            }
        }
    }
    debug=false;
    if(debug)
    {
        std::cout << "true cases:\n";
        printAllAttValuePairs(trueCases);
        std::cout << "\n\nfalse cases:\n";
        printAllAttValuePairs(falseCases);
    }
    for(unsigned int em = 0; em<concepts.size(); em++)
    {
        curConcept = concepts[em];
        trueCases.clear();
        falseCases.clear();
        for(unsigned int i = 0; i< cases.size(); i++)
        {
            if(cases[i].back().equals(curConcept))
            {
                trueCases.push_back(cases[i]);
            }
            else
            {
                falseCases.push_back(cases[i]);
            }
        }
        for(unsigned int i = 0; i<trueCases.size(); i++)//goes through each seed
        {
    //        ruleptr = new Rule(trueCases[i].back());//make the new rule, the concept for that rule is the ith attributevalue
            for(unsigned int j = 0; j<falseCases.size(); j++)
            {//goes through the false case for each seed
                if(!passesRules(singleSeedRules,falseCases[j]))
                {
                    //do nothing
                    debug = false;
                    if(debug)
                    {
                        //std::cout << "skips case " << j << " passes rule\n";
                        for(unsigned int el=0; el<singleSeedRules.size(); el++)
                        {
                            singleSeedRules[el].print();
                            std::cout << "\n";
                        }
                    }
                }
                else
                {
                    ruleptr = new Rule(trueCases[i].back());
                    for(int k = 0; k<numAttributes; k++)
                    {
                        if(!trueCases[i][k].equals(falseCases[j][k]))//not same, add to rule
                        {
                            ruleptr->addNegCondition(falseCases[j][k]);
                        }
                    }
                    singleSeedRules = combineRules(singleSeedRules,*(ruleptr));
                    debug = false;
                    if(debug)
                    {
                        std::cout << "printing rules\n";
                        for(unsigned int el=0; el<singleSeedRules.size(); el++)
                        {
                            singleSeedRules[el].print();
                            std::cout << "\n";
                        }
                    }
                }
            }
            rules = appendRuleVectors(rules,singleSeedRules);
            singleSeedRules.clear();
        }
    }
    // if(isConsistent(cases))
    // {
    //     std::cout << "consistent\n";
    // }
    // else
    // {
    //     std::cout << "inconsistent\n";
    // }

    rules = reduceRules(rules);
    std::string negFileName;
    std::string noNegFileName;

    filename.pop_back();
    filename.pop_back();
    filename.pop_back();
    filename.pop_back();
    negFileName+=filename;
    noNegFileName+=filename;
    negFileName+=".with.negation.rul";
    noNegFileName+=".without.negation.rul";

    std::ofstream negFile(negFileName);
    std::ofstream noNegFile(noNegFileName);

    if(!isConsistent(cases))
    {
        negFile << "! The input data set is inconsistent\n";
        noNegFile << "! The input data set is inconsistent\n";
    }

    for(unsigned int i = 0; i<rules.size(); i++)
    {
//        rules[i].printNegation(negFile);
        negFile << rules[i].printString();
        negFile << "\n";
    }

    std::vector<std::vector<AttValuePair>> allPairsWithoutConcepts = allPairs;
    allPairsWithoutConcepts.pop_back();
    rules = eliminateNegation(rules, allPairsWithoutConcepts);
    for(unsigned int i = 0; i<rules.size(); i++)
    {
        noNegFile << rules[i].printString();
        noNegFile << "\n";
    }


    return 0;
}
