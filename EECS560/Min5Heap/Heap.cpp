/**
*     @file       Heap.cpp
*     @author     Austin bailey
*     @date       9/27/2016
*/
#include "Heap.h"

Heap::Heap()
{
      int temp;
      lastElementIndex=0;
      std::ifstream file("data.txt");
      while(file.good())
      {
            file>>temp;
            insert(temp);
      }

}

Heap::~Heap()
{

}

bool Heap::insert(int value)
{
      if(lastElementIndex>=500)
      {
//            std::cout << "Array is full, cannot insert\n";
            return false;
      }
//This code prevents duplicate values and is unnecessary for this implementation
//       if(search(value))
//       {
// //            std::cout << "Value already in array\n";
//             return false;
//       }
      if(lastElementIndex==0)//handles empty case
      {
//            std::cout << "inserting " << value << " first \n";
            content[lastElementIndex]=value;
//            levelorder();
            lastElementIndex++;
            return true;
      }
      if(lastElementIndex>0)
      {
//            std::cout << "inserting " << value << "\n";
            content[lastElementIndex]=value;

//            std::cout << "\nbefore upheap\n";
//            levelorder();
            upheap(lastElementIndex);
            lastElementIndex++;
            return true;
      }
      return true;
}

void Heap::upheap(int index)
{
      //if parent is larger than child
       if(content[(index-1)/5]>content[index])
       {
             int temp=content[index];
//             std::cout << "temp =" << temp << "\n";
//             std::cout << "content[index] = " << content[index] << "\n";
//             std::cout << "content[(index-1)/5] = " <<content[(index-1)/5] << "\n";
             content[index]=content[(index-1)/5];
             content[(index-1)/5]=temp;
//             std::cout << "content[index] = " << content[index] << "\n";
//             std::cout << "content[(index-1)/5] = " << content[(index-1)/5] << "\n";
//             std::cout << "\nafter upheap\n";
//             levelorder();
             upheap((index-1)/5);
       }
}

bool Heap::deletemin()
{
      if(lastElementIndex==0)
      {
            std::cout << "Heap is empty";
            return false;
      }
      else if(lastElementIndex == 1)
      {
            content[0]=0;
            content[1]=0;
            lastElementIndex--;
            return true;
      }
      else
      {
            levelorder();
            content[0]=content[lastElementIndex-1];
//            std::cout << "problem is with downheap\n";
            downheap(0);
            std::cout << "after downheap\n";
            levelorder();
            content[lastElementIndex-1]=0;
            lastElementIndex--;
            return true;
      }
      return true;
}

void Heap::downheap(int index)
{
      std::cout << "\ndownheaping index  " << index << "\n";
      std::cout << "content[index] = " << content[index] <<"\n";
      levelorder();
      std::cout << "\n";
      int temp;
      if( (content[(5*index) +1]<content[index]) && ( ((5*index)+1)<lastElementIndex) && (content[(5*index) +1]<=content[(5*index) +2]) && (content[(5*index) + 1] <= content[(5*index) + 3]) && (content[(5*index) + 1] <= content[(5*index) +4]) && (content[(5*index) + 1] <= content[(5*index) + 5]) )
      {
            temp=content[index];
            content[index]=content[(5*index) +1];
            content[(5*index)+1]=temp;
            downheap((5*index)+1);
      }
      else if( (content[(5*index) +2]<content[index]) && ( ((5*index)+2)<lastElementIndex) && (content[(5*index) +2] <= content[(5*index) + 3]) && (content[(5*index) +2] <=content[(5*index)+4]) && (content[(5*index) +2] <= content[(5*index)+5]))
      {
            temp=content[index];
            content[index]=content[(5*index) +2];
            content[(5*index)+2]=temp;
            downheap((5*index)+2);
      }
      else if( (content[(5*index) +3]<content[index]) && ( ((5*index)+3)<lastElementIndex) && (content[(5*index)+3] <= content[(5*index)+4]) && (content[(5*index)+3]<=content[(5*index) +5]))
      {
            temp=content[index];
            content[index]=content[(5*index) +3];
            content[(5*index)+3]=temp;
            downheap((5*index)+3);
      }
      else if( (content[(5*index) +4]<content[index]) && ( ((5*index)+4)<lastElementIndex) &&(content[(5*index)+4]<= content[(5*index)+5]))
      {
            temp=content[index];
            content[index]=content[(5*index) +4];
            content[(5*index)+4]=temp;
            downheap((5*index)+4);
      }
      else if( (content[(5*index) +5]<content[index]) && ( ((5*index)+5)<lastElementIndex) )
      {
            temp=content[index];
            content[index]=content[(5*index) +5];
            content[(5*index)+5]=temp;
            downheap((5*index)+5);
      }

}
bool Heap::deletemax()
{
      if(lastElementIndex==0)
      {
            std::cout << "The tree is empty";
            return false;
      }
      else if(lastElementIndex==1)//were gonna have trouble with lastElementIndex
      {
            content[0]=0;
            lastElementIndex--;
      }
      int max=content[0];
      int maxIndex=0;
      for(int i=0;i<=lastElementIndex;i++)//this loop finds the maximum value and the index of that value
      {
            if(max<content[i])
            {
                  max=content[i];
                  maxIndex=i;
            }
      }
      //The following code is for debugging
      //std::cout << "max: " << max << "\n";
      //std::cout << "maxIndex: " << maxIndex << "\n";
      if(maxIndex==lastElementIndex)
      {
            content[lastElementIndex]=0;
            lastElementIndex--;
            return true;
      }
      else
      {
            content[maxIndex]=content[lastElementIndex-1];//moves the last element to the position
            //of the largest element
            lastElementIndex--;
            content[lastElementIndex]=0;

            upheap(maxIndex);
            return true;
      }
      return true;
}

bool Heap::remove2(int value)
{
      if(lastElementIndex==0)
      {
            std::cout << "Cannot remove from an empty heap";
      }
      int index=-1;
      for(int i=0;i<=lastElementIndex;i++)
      {
            if(content[i]==value)
            {
                  index=i;
                  while(content[lastElementIndex-1]==value)//handles case where we would be downheaping a
                  {//duplicate value
                        content[lastElementIndex-1]=0;
                        lastElementIndex--;
                  }
                  content[i]=content[lastElementIndex-1];
                  lastElementIndex--;
                  content[lastElementIndex]=0;
                  downheap(i);
            }
      }
      if(index==-1)
      {
            std::cout << "Value is not in Heap";
            return false;
      }
      else
      {
            return true;
      }
}

void Heap::levelorder()
{
//      std::cout << "The last Element Index is: " << lastElementIndex << "\n";
      for(int i=0;i<lastElementIndex;i++)
      {
            std::cout << content[i] << " ";
            if(i==0||i==5||i==25||i==125)
            {
                  std::cout <<"\n";
            }
            if(i>6&&i%5==0)
            {
                  std::cout << "- ";
            }
      }
//The following code is for debugging
//      std::cout << "\n";
//      std::cout << "LastElementIndex = " << lastElementIndex << "\n";
//      std::cout << "content[lastElementIndex] = " << content[lastElementIndex] << "\n";
}

bool Heap::search(int value)
{
      for(int i=0; i<=lastElementIndex;i++)
      {
            if(content[i]==value)
            {
                  return true;
            }
      }
      return false;
}
