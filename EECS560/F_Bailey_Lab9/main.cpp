/**
*     @file:            main.cpp
*     @author:          Austin Bailey
*     @date:            11/4/16
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>//rand,srand
#include <time.h>
#include <sys/time.h>
#include "SkewHeap.h"
#include "LeftistHeap.h"
#include "Node.h"
#include "Queue.h"

int main()
{
      timeval start;
      timeval end;
      double seconds = 0.0;
      SkewHeap* skew;
      LeftistHeap* left;
      int n;
      double trialRecord[40];
      double average;
      //Skew Heap build trails
      for(int i=0; i<20; i++)
      {
            srand(i);//sets the random seed to a changing arbitrary value
            skew = new SkewHeap();
            if(i<5)
            {
                  n=50000;
            }
            else if(i<10)
            {
                  n=100000;
            }
            else if(i<15)
            {
                  n=200000;
            }
            else
            {
                  n=400000;
            }
            gettimeofday(&start, NULL);
            for(int j=0; j<n; j++)
            {
                  skew->insert(skew->getRoot(),rand()%(4*n)+1);
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;//store the result
            std::cout << "Skew Insert " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " inserts to a Skew heap is: " << average << "\n\n";
            }
      }
      //Leftist heap build trials
      for(int i=0; i<20; i++)
      {
            srand(i);//sets the random seed to a changing arbitrary value
            left = new LeftistHeap(false);
            if(i<5)
            {
                  n=50000;
            }
            else if(i<10)
            {
                  n=100000;
            }
            else if(i<15)
            {
                  n=200000;
            }
            else
            {
                  n=400000;
            }
            gettimeofday(&start, NULL);
            for(int j=0; j<n; j++)
            {
                  left->insert(left->getRoot(),rand()%(4*n)+1);
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;//store the result
            std::cout << "Leftist Insert " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " inserts to a Leftist heap is: " << average << "\n\n";
            }
      }
      //LeftistHeap random tests

      for(int i=20; i<40; i++)
      {
            srand(i);
            if(i<25)
            {
                  n=50000;
            }
            else if(i<30)
            {
                  n=100000;
            }
            else if(i<35)
            {
                  n=200000;
            }
            else
            {
                  n=400000;
            }
            left= new LeftistHeap(false);
            for(int j=0; j<n/10;j++)
            {
                  left->insert(left->getRoot(),rand()%(4*n)+1);
            }
            gettimeofday(&start,NULL);
            for(int j=0; i<n/10;j++)
            {
//                  randselector = rand()%2;
//                  if(randselector==0)
//                  {
                        left->deleteMin();
//                  }
//                  else
//                  {
//                        left->insert(left->getRoot(),rand()%(4*n)+1);
//                  }
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "Leftist RandomFunctions " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " RandomFunctions by a Leftist Heap is " << average << "\n\n";
            }
      }
      //Skew Heap random operation trials
      int randselector;

      for(int i=20; i<40; i++)
      {
            srand(i);
            if(i<25)
            {
                  n=50000;
            }
            else if(i<30)
            {
                  n=100000;
            }
            else if(i<35)
            {
                  n=200000;
            }
            else
            {
                  n=400000;
            }
            skew = new SkewHeap();
            for(int j=0; j<n/5;j++)
            {
                  skew->insert(skew->getRoot(),rand()%(4*n)+1);
            }
            gettimeofday(&start,NULL);
            for(int j=0; i<n/10;j++)
            {
                  if(rand()%2==0)
                  {
                        skew->deleteMin();
                  }
                  else
                  {
                        skew->insert(skew->getRoot(),rand()%(4*n)+1);
                  }
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "Skew RandomFunctions " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " RandomFunctions by a Skew Heap is " << average << "\n\n";
            }
      }

}






      // int choice;
      // bool exit = false;
      // SkewHeap* sh = new SkewHeap();
      // while(!exit)
      // {
      //       std::cout << "\n\n........................................\n";
      //       std::cout << "Please choose one fo the following commands\n";
      //       std::cout << "1-insert\n2-deletemin\n3-preorder\n4-inorder\n";
      //       std::cout << "5-Levelorder\n6-end\n\n";
      //       std::cin >> choice;
      //       if(choice==1)
      //       {
      //             std::cout << "What value would you like to insert?\n";
      //             std::cin >>choice;
      //             sh->insert(sh->getRoot(),choice);
      //       }
      //       else if(choice==2)
      //       {
      //             sh->deleteMin();
      //       }
      //       else if(choice==3)
      //       {
      //             std::cout << "\n\n";
      //             sh->preOrder(sh->getRoot());
      //       }
      //       else if(choice==4)
      //       {
      //             std::cout << "\n\n";
      //             sh->inOrder(sh->getRoot());
      //       }
      //       else if(choice==5)
      //       {
      //             std::cout << "\n\n";
      //             sh->levelOrder(sh->getRoot());
      //       }
      //       else if(choice==6)
      //       {
      //             exit=true;
      //             return 0;
      //       }
      //       else
      //       {
      //             std::cout << "Sorry, we didn't understand your input, please";
      //             std::cout << "Input a 1,2,3,4,5 or 6\n";
      //       }
      // }
//}
