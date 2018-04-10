/*
*     @file:      main.cpp
*     @author:    Austin Baiiley
*     @date:      10/22/2015
*/

#include <iostream>
#include <fstream>
#include "minMax.h"
int main()
{
      bool exit =false;
      int choice;
      minMax* myHeap = new minMax(500);
      while(!exit)
      {
            std::cout << "Please choose one of the following commands;\n";
            std::cout << "1- insert\n2- deletemin\n3- deletemax\n4- levelorder\n";
            std::cout << "5- exit\n\n";
            std::cin >> choice;
            if(choice==1)
            {
                  std::cout << "Please insert the number that you want to be ";
                  std::cout << "inserted in the tree\n";
                  std::cin >> choice;
                  myHeap->insert(choice);
            }
            else if (choice==2)
            {
                  myHeap->deletemin();
            }
            else if(choice==3)
            {
                  myHeap->deletemax();
            }
            else if(choice==4)
            {
                  std::cout << "\n\n";
                  myHeap->levelorder();
            }
            else if(choice==5)
            {
                  exit=true;
            }
            else
            {
                  std::cout << "Your input was incorrect, please input an inte";
                  std::cout << "ger between 1 and 5\n";
            }
      }

      return 0;
}
