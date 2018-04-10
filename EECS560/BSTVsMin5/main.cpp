/**
*     @file:            main.cpp
*     @author:          Austin Bailey
*     @date:            9/20/2016
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>//rand,srand
#include <time.h>
#include <sys/time.h>
#include "BinarySearchTree.h"
#include "Node.h"
#include "Heap.h"


int main()
{
      timeval start;
      timeval end;
      double seconds=0.0;
      BinarySearchTree* bst;
      Heap* heap;
      int n;
      double trialRecord[40];
      double average;
      //BST Insert trials
      for(int i=0; i<20; i++)
      {
            srand(i);
            bst = new BinarySearchTree();
            //picks an n
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
            gettimeofday(&start,NULL);//sets the timer
            for(int j=0; j<n; j++)//inserts the data
            {
                  bst->insert(rand()%(4*n) +1,bst->getRoot());
            }
            gettimeofday(&end,NULL);//ends the timer
            //calculates the difference between times
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "BST insert " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " Inserts to a BST is " << average <<"\n\n";
            }
      }
      //HEAP Insert trials
      for(int i=0; i<20; i++)
      {
            srand(i);//srand is the same for the cooresponding heap

            //picks an n
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
            heap = new Heap(n);


            gettimeofday(&start,NULL);//sets the timer
            for(int j=0; j<n; j++)//inserts the data
            {
                  heap->insert(rand()%(4*n) +1);
            }
            gettimeofday(&end,NULL);//ends the timer
            //calculates the difference between times
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "Heap insert " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " Inserts to a Heap is " << average << "\n\n";
            }
      }


      //BST Operation trials
      double randselector;
      int deletenum;
      int insertnum;
      for(int i=20; i<40; i++)
      {
            srand(i);//sets the generator seed to i
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

            bst = new BinarySearchTree();//generate the bst

            for(int j=0; j<n/10;j++)//this loop loads numbers into the bst
            {
                  bst->insert(rand()%(4*n) +1,bst->getRoot());
            }
            gettimeofday(&start,NULL);
            for(int j=0; j<n/10;j++)
            {
                  //randselector=(rand()%4);
                  // if(randselector==0)
                  // {
                  //       std::cout << "is it deleteMin?\n";
                  //       bst->deleteMin();
                  //       std::cout << "it is not deleteMin\n";
                  // }
                  // else if(randselector==1)
                  // {
                  //       std::cout << "is it deleteMax?\n";
                  //       bst->deleteMax();
                  //       std::cout << "it is not DeleteMax\n";
                  // }
                  // else if(randselector==2)
                  // {
                  //       std::cout << "is it remove?\n";
                  //       deletenum=rand()%(4*n)+1;
                  //       bst->remove(deletenum,bst->getRoot());
                  //       std::cout << "it is not remove\n";
                  // }
                  // else if(randselector==3)
                  // {
                  //       std::cout << "is it insertnum?\n";
                        insertnum=rand()%(4*n)+1;
                        bst->insert(insertnum,bst->getRoot());
                  //       std::cout << "it is not insertnum\n";
                  // }
                  // else
                  // {
                  //       std::cout << "ERROR randselector = " << randselector << "\n";
                  // }
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "BST randomFunction " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " RandomFunctions by a BST is " << average << "\n\n";
            }
      }

      //Heap Operation Trials

      for(int i=20; i<40; i++)
      {
            srand(i);//sets the generator seed to i
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

            heap = new Heap(n);//generate the bst

            for(int j=0; j<n/10;j++)//this loop loads numbers into the bst
            {
                  heap->insert(rand()%(4*n) +1);
            }
            gettimeofday(&start,NULL);
            for(int j=0; j<n/10;j++)
            {
                  randselector=(rand()%4);
                  if(randselector==0)
                  {
//                        std::cout << "is it deleteMin?\n";
                        heap->deletemin();
//                        std::cout << "it is not deleteMin\n";
                  }
                  else if(randselector==1)
                  {
//                        std::cout << "is it deleteMax?\n";
                        heap->deletemax();
//                        std::cout << "it is not DeleteMax\n";
                  }
                  else if(randselector==2)
                  {
//                        std::cout << "is it remove?\n";
                        deletenum=rand()%(4*n)+1;
                        heap->remove2(deletenum);
//                        std::cout << "it is not remove\n";
                  }
                  else if(randselector==3)
                  {
//                        std::cout << "is it insertnum?\n";
                        insertnum=rand()%(4*n)+1;
                        heap->insert(insertnum);
//                        std::cout << "it is not insertnum\n";
                  }
                  else
                  {
                        std::cout << "ERROR randselector = " << randselector << "\n";
                  }
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "Heap randomFunction " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " RandomFunctions by a Heap is " << average << "\n\n";
            }
      }
      return 0;
}


//report
/*
        Build                   Operation
      BST    Heap             BST     Heap
50000 //test1
      //test2
      //test3
      //test4
      //test5
      //AVG(1-5)
repeat for 100000,200000,400000

*/
