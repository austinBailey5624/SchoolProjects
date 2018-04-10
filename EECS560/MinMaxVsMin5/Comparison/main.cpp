/**
*     @file       main.cpp
*     @author     Austin bailey
*     @date       9/27/2016
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>//rand,srand
#include <time.h>
#include <sys/time.h>

#include "Heap.h"
#include "minMax.h"
int main()
{
      double average;
      int insertnum;
      int randselector;
      timeval start;
      timeval end;
      double seconds=0.0;
      Heap* heap;
      minMax* myMinMax;
      int n;
      double trialRecord[40];

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
            heap = new Heap();


            gettimeofday(&start,NULL);//sets the timer
            for(int j=0; j<n; j++)//inserts the data
            {
                  heap->insert(rand()%(4*n) +1);
            }
            gettimeofday(&end,NULL);//ends the timer
            //calculates the difference between times
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "Min5Heap insert " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " Inserts to a Min5Heap is " << average << "\n\n";
            }
      }
      //minMax build timing
      for(int i=0; i<20; i++)
      {
            srand(i);
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
            myMinMax= new minMax(n);
            gettimeofday(&start,NULL);//sets the timer
            myMinMax=new minMax(n);//build is utilized in the constructor
            gettimeofday(&end,NULL);//ends the timer
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "MinMax Build " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " Building a minMax " << average << "\n\n";
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

            heap = new Heap();//generate the bst

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
                        heap->deletemin();
                  }
                  else if(randselector==1)
                  {
                        heap->deletemax();
                  }
                  else if(randselector==2||randselector==3)
                  {
                        insertnum=rand()%(4*n)+1;
                        heap->insert(insertnum);
                  }
                  else
                  {
                        std::cout << "ERROR randselector = " << randselector << "\n";
                  }
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "Min5Heap randomFunction " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " RandomFunctions by a Min5Heap is " << average << "\n\n";
            }
      }

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
            myMinMax = new minMax(n);
            gettimeofday(&start,NULL);
            for(int j=0; j<n/10;j++)
            {
                  randselector=(rand()%4);
                  if(randselector==0)
                  {
                        myMinMax->deletemin();
                  }
                  else if(randselector==1)
                  {
                        myMinMax->deletemax();
                  }
                  else if(randselector==2||randselector==3)
                  {
                        insertnum = rand()%(4*n)+1;
                        myMinMax->insert(insertnum);
                  }
                  else
                  {
                        std::cout <<"ERROR randselector = " << randselector<< "\n";
                  }
            }
            gettimeofday(&end,NULL);
            seconds=(end.tv_sec - start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0;
            trialRecord[i]=seconds;
            std::cout << "MinMaxHeap randomFunction " << n << " trial " << i%5+1 << " took " << seconds << " seconds \n";
            if(i%5==4)//case where we should output five-case average to screen
            {
                  average =(trialRecord[i-4]+trialRecord[i-3]+trialRecord[i-2]+trialRecord[i-1]+trialRecord[i])/5;
                  std::cout << "Average of 5 trials of " << n << " RandomFunctions by a MinMaxHeap is " << average << "\n\n";
            }
      }
      return 0;
}
