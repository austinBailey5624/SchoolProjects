/**
*     @file:            main.cpp
*     @author:          Austin Bailey
*     @date:            11/4/16
*/

#include <iostream>
#include <fstream>
#include "LeftistHeap.h"
#include "Node.h"
#include "Queue.h"

int main()
{
      int choice;
      bool exit = false;
      LeftistHeap* lh = new LeftistHeap(true);
      while(!exit)
      {
            std::cout << "\n\n........................................\n";
            std::cout << "Please choose one fo the following commands\n";
            std::cout << "1-insert\n2-deletemin\n3-preorder\n4-inorder\n";
            std::cout << "5-Levelorder\n6-end\n\n";
            std::cin >> choice;
            if(choice==1)
            {
                  std::cout << "What value would you like to insert?\n";
                  std::cin >>choice;
                  lh->insert(lh->getRoot(),choice);
            }
            else if(choice==2)
            {
                  lh->deleteMin();
            }
            else if(choice==3)
            {
                  std::cout << "\n\n";
                  lh->preOrder(lh->getRoot());
            }
            else if(choice==4)
            {
                  std::cout << "\n\n";
                  lh->inOrder(lh->getRoot());
            }
            else if(choice==5)
            {
                  std::cout << "\n\n";
                  lh->levelOrder(lh->getRoot());
            }
            else if(choice==6)
            {
                  exit=true;
                  return 0;
            }
            else
            {
                  std::cout << "Sorry, we didn't understand your input, please";
                  std::cout << "Input a 1,2,3,4,5 or 6\n";
            }
      }
}
