/**
*     @file       main.cpp
*     @author     Austin bailey
*     @date       9/27/2016
*/
#include <iostream>
#include <fstream>
#include "Heap.h"
int main()
{
      Heap* myHeap = new Heap();
      bool exit=false;
      int choice;
      while(!exit)
      {
            std::cout << "\n......................................\n";
            std::cout << "Please choose one of the following commands\n";
            std::cout << "1- insert\n2- deletemin\n3- deletemax\n4- remove\n";
            std::cout << "5- levelorder\n6- exit\n";
            std::cin >> choice;
            if(choice==1)
            {
                  std::cout << "What value would you like to insert?\n";
                  std::cin >> choice;
                  if(myHeap->insert(choice))
                  {
                        std::cout << choice << " inserted\n";
                  }
                  else
                  {
                        std::cout << "Failed to insert " << choice << "\n";
                  }
            }
            else if(choice==2)
            {
                  if(myHeap->deletemin())
                  {
                        std::cout << "deletemin completed successfully\n";
                  }
                  else
                  {
                        std::cout << "could not deletemin\n";
                  }
            }
            else if(choice==3)
            {
                  if(myHeap->deletemax())
                  {
                        std::cout << "deletemax completed successfully\n";
                  }
                  else
                  {
                        std::cout << "could not deletemax\n";
                  }
            }
            else if(choice==4)
            {
                  std::cout << "What value would you like to remove?\n";
                  std::cin >> choice;
                  if(myHeap->remove2(choice))
                  {
                        std::cout << choice << " removed successuflly\n";
                  }
                  else
                  {
                        std::cout << choice << " was not removed\n";
                  }
            }
            else if(choice==5)
            {
                  std::cout << "printing levelorder\n";
                  myHeap->levelorder();
            }
            else if(choice==6)
            {
                  std::cout << "Exiting";
                  return(0);
            }
            else
            {
                  std::cout << "Sorry we didn't understand your input please input a 1,2,3,4,5,or 6";
            }
      }
      return 0;
}
