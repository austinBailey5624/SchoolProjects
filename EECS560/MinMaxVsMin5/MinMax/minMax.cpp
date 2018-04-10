/*
*     @file:      minMax.cpp
*     @author:    Austin bailey
*     @date:      10/22/2016
*/

#include "minMax.h"

minMax::minMax(int size)
{
      if(size<500)
      {
            m_size=500;
      }
      else
      {
            m_size = size;
      }
      m_lastIndex=0;
      m_content= new int[size];
      for(int i=0; i < m_size; i++)
      {
            m_content[i]=-1;
      }
      std::ifstream file("data.txt");
      int i=0;
      while(file.good()&&i<m_size)
      {
            m_lastIndex++;
            file>>m_content[m_lastIndex];

      //      std::cout << "m_lastIndex= " << m_lastIndex << "\n";
      //      levelorder();
      }
      if(m_lastIndex==1)
      {
            return;
      }
      m_lastIndex--;
      int indexLastNonLeaf=m_lastIndex/2;
      // if(m_lastIndex%2==0)
      // {
      //       indexLastNonLeaf=(int)((m_lastIndex-2)/2);
      // }
      // else
      // {
      //       indexLastNonLeaf=(int)((m_lastIndex-1)/2);
      // }
//      std::cout << "m_lastIndex =" << m_lastIndex << "\n";
//      std::cout << "\nheap before trickleDown\n";
//      levelorder();
      for(;indexLastNonLeaf>=0;indexLastNonLeaf--)
      {
            trickleDown(indexLastNonLeaf);
//            std::cout << "\n Heap after trickledown on index " << indexLastNonLeaf << "\n";
//            levelorder();
      }

      // for(int i=indexLastNonLeaf; i>=0;i--)
      // {
      // if(isMinNode(indexLastNonLeaf))//minNodeCase
      // {
      //       if(rightChild(indexLastNonLeaf)!=-1)//if it has a right child
      //       {     //if the right child is greater than the left child
      //             if(m_content[rightChild(indexLastNonLeaf)]>(m_content[leftChild(indexLastNonLeaf)]))
      //             {     //if the right child is greater than the index
      //                   if(m_content[rightChild(indexLastNonLeaf)]>m_content[indexLastNonLeaf])
      //                   {     //swap
      //                         temp=m_content[indexLastNonLeaf];
      //                         m_content[indexLastNonLeaf]=m_content[rightChild(indexLastNonLeaf)];
      //                         m_content[rightChild(indexLastNonLeaf)]=temp;
      //                   }
      //             }
      //             else//if the left child is <= right child
      //             {     //if left child is > index swap
      //                   if(m_content[leftChild(indexLastNonLeaf)]>m_content[indexLastNonLeaf])
      //                   {     //swap
      //                         temp=m_content[indexLastNonLeaf];
      //                         m_content[indexLastNonLeaf]=m_content[leftChild(indexLastNonLeaf)];
      //                         m_content[leftChild(indexLastNonLeaf)]=temp;
      //                   }
      //             }
      //       }
      //       else//case where no right child exists and there is only one comparison
      //       {
      //             if(m_content[leftChild(indexLastNonLeaf)]>m_content[indexLastNonLeaf])
      //             {     //swap
      //                   temp=m_content[indexLastNonLeaf];
      //                   m_content[indexLastNonLeaf]=m_content[leftChild(indexLastNonLeaf)];
      //                   m_content[leftChild(indexLastNonLeaf)]=temp;
      //             }
      //       }
      // }
      // else//maxNodeCase
      // {
      //       if(rightChild(indexLastNonLeaf)!=-1)//if it has a right child
      //       {     //if the right child is greater than the left child
      //             if(m_content[rightChild(indexLastNonLeaf)]<(m_content[leftChild(indexLastNonLeaf)]))
      //             {     //if the right child is greater than the index
      //                   if(m_content[rightChild(indexLastNonLeaf)]<m_content[indexLastNonLeaf])
      //                   {     //swap
      //                         temp=m_content[indexLastNonLeaf];
      //                         m_content[indexLastNonLeaf]=m_content[rightChild(indexLastNonLeaf)];
      //                         m_content[rightChild(indexLastNonLeaf)]=temp;
      //                   }
      //             }
      //             else//if the left child is >= right child
      //             {     //if left child is < index swap
      //                   if(m_content[leftChild(indexLastNonLeaf)]<m_content[indexLastNonLeaf])
      //                   {     //swap
      //                         temp=m_content[indexLastNonLeaf];
      //                         m_content[indexLastNonLeaf]=m_content[leftChild(indexLastNonLeaf)];
      //                         m_content[leftChild(indexLastNonLeaf)]=temp;
      //                   }
      //             }
      //       }
      //       else//case where no right child exists and there is only one comparison
      //       {
      //             if(m_content[leftChild(indexLastNonLeaf)]<m_content[indexLastNonLeaf])
      //             {     //swap
      //                   temp=m_content[indexLastNonLeaf];
      //                   m_content[indexLastNonLeaf]=m_content[leftChild(indexLastNonLeaf)];
      //                   m_content[leftChild(indexLastNonLeaf)]=temp;
      //             }
      //       }
      // }
      // }
}

minMax::~minMax()
{
      delete m_content;
}

void minMax::insert(int value)
{
      if(m_lastIndex==0)//empty case
      {
            m_content[1]=value;
            m_lastIndex++;
            return;
      }
      else
      {
            m_lastIndex++;
            m_content[m_lastIndex]=value;//puts the value in its place
            if(m_content[m_lastIndex/2]<value)//its a minnode Case
            {//if a parent is less than the new child
                  if(!isMinNode(m_lastIndex/2))
                  {
                        int temp=m_content[m_lastIndex];
                        m_content[m_lastIndex]=m_content[m_lastIndex/2];
                        m_content[m_lastIndex/2]=temp;
                        bubbleUp(m_lastIndex/2);
                  }
            }
            else if(m_content[m_lastIndex/2]>value)//its a maxnode Case
            {
                  if(isMinNode(m_lastIndex/2))
                  {
                        int temp=m_content[m_lastIndex];
                        m_content[m_lastIndex]=m_content[m_lastIndex/2];
                        m_content[m_lastIndex/2]=temp;
                        bubbleUp(m_lastIndex/2);
                  }
            }
            return;
      }

}

// void minMax::remove(int value)
// {
//
// }

void minMax::deletemin()
{
      if(m_lastIndex<=0)//empty case;
      {
            m_lastIndex=0;
            return;
      }
      if(m_lastIndex==1)//size==1 case
      {
            m_lastIndex=-1;
            m_lastIndex--;
            return;
      }
      int smallestIndex=2;
      if(m_lastIndex>=3)//case where the size >=3 so check the right child
      {
            if(m_content[smallestIndex]>m_content[3])
            {
                  smallestIndex=3;
            }
      }
      if(m_lastIndex>=4)//leftleftchild
      {
            if(m_content[smallestIndex]>m_content[4])
            {
                  smallestIndex=4;
            }
      }
      if(m_lastIndex>=5)//leftRightChild
      {
            if(m_content[smallestIndex]>m_content[5])
            {
                  smallestIndex=5;
            }
      }
      if(m_lastIndex>=6)//rightLeftChild
      {
            if(m_content[smallestIndex]>m_content[6])
            {
                  smallestIndex=6;
            }
      }
      if(m_lastIndex>=7)
      {
            if(m_content[smallestIndex]>m_content[7])
            {
                  smallestIndex=7;
            }
      }
      if(m_lastIndex==smallestIndex)
      {
            m_content[1]=m_content[m_lastIndex];
            m_content[m_lastIndex]=-1;
            m_lastIndex--;
            return;
      }
      else if(m_content[m_lastIndex]>m_content[smallestIndex])
      {
            m_content[1]=m_content[smallestIndex];//patch the hole
            m_content[smallestIndex]=m_content[m_lastIndex];
            // if(isMinNode(m_content[smallestIndex/2]))//if your new parent is a minnode
            // {
            //       if(m_content[smallestIndex]<m_content[smallestIndex/2])//and your smaller than them
            //       {
            //
            //       }
            // }
            bubbleUp(smallestIndex);
            m_lastIndex--;
            return;
      }
      else
      {
            m_content[1]=m_content[m_lastIndex];
            m_lastIndex--;
      }
}

void minMax::deletemax()
{
      if(m_lastIndex<=0)
      {
            m_lastIndex=0;
            return;
      }
      if(m_lastIndex==1)
      {
            m_content[1]=-1;
            m_lastIndex--;
            return;
      }
      else if(m_lastIndex==2)
      {
            m_content[2]=-1;
            m_lastIndex--;
            return;
      }
      else
      {
            int largestIndex;
            if(m_content[2]>=m_content[3])
            {
                  m_content[2]=-1;
                  largestIndex=4;
                  if(m_content[5]>m_content[largestIndex])
                  {
                        largestIndex=5;
                  }
                  if(m_content[8]>m_content[largestIndex])
                  {
                        largestIndex=8;
                  }
                  if(m_content[9]>m_content[largestIndex])
                  {
                        largestIndex=9;
                  }
                  if(m_content[10]>m_content[largestIndex])
                  {
                        largestIndex=10;
                  }
                  if(m_content[11]>m_content[largestIndex])
                  {
                        largestIndex=11;
                  }
                  if(largestIndex==m_lastIndex)
                  {
                        m_content[2]=m_content[largestIndex];
                        m_lastIndex--;
                        return;
                  }
                  if(m_content[largestIndex]>m_content[m_lastIndex])
                  {
                        m_content[2]=m_content[largestIndex];
                        m_content[largestIndex]=m_content[m_lastIndex];
                        bubbleUp(largestIndex);
                        m_lastIndex--;
                        return;
                  }
                  else
                  {
                        m_content[2]=m_content[m_lastIndex];
                        m_lastIndex--;
                        return;
                  }
            }
            else//index three has the largest
            {
                  m_content[3]=-1;//make the hole
                  largestIndex=6;
                  if(m_content[7]>m_content[largestIndex])
                  {
                        largestIndex=7;
                  }
                  if(m_content[12]>m_content[largestIndex])
                  {
                        largestIndex=12;
                  }
                  if(m_content[13]>m_content[largestIndex])
                  {
                        largestIndex=13;
                  }
                  if(m_content[14]>m_content[largestIndex])
                  {
                        largestIndex=14;
                  }
                  if(m_content[15]>m_content[largestIndex])
                  {
                        largestIndex=15;
                  }
                  if(largestIndex==m_lastIndex)
                  {
                        m_content[3] = m_content[largestIndex];
                        m_lastIndex--;
                        return;
                  }
                  else if(m_content[largestIndex]>m_content[m_lastIndex])
                  {
                        m_content[3]=m_content[largestIndex];
                        m_content[largestIndex]=m_content[m_lastIndex];
                        bubbleUp(largestIndex);
                        m_lastIndex--;
                        return;
                  }
                  else
                  {
                        m_content[3]=m_content[m_lastIndex];
                        m_lastIndex--;
                        return;
                  }
            }
      }
}

void minMax::levelorder()
{
      for(int i=1; i<= m_lastIndex;i++)
      {
            std::cout << m_content[i] << " ";
            if(i==1||i==3||i==7||i==15||i==31)
            {
                  std::cout << "\n";
            }

      }
      std::cout << "\n\n";
}

void minMax::bubbleUp(int index)
{
      if(isMinNode(index))//minNodeCase
      {
            if(index/4<=0)//checks to see if were going outside bounds
            {
                  return;
            }
            if(m_content[index]<m_content[index/4])//case where we should switch
            {     //swaps the two values
                  int temp=m_content[index/4];
                  m_content[index/4]=m_content[index];
                  m_content[index]=temp;
                  bubbleUp(index/4);//recurses up
            }
            else//case where we don't switch
            {
                  return;
            }
      }
      else//MaxNodeCase
      {
            if(index/4<=0)//checks bounds, terminates recursion
            {
                  return;
            }
            if(m_content[index]>m_content[index/4])//case where you should switch
            {
                  int temp=m_content[index/4];
                  m_content[index/4]=m_content[index];
                  m_content[index]=temp;
                  bubbleUp(index/4);
            }
            else
            {
                  return;
            }
      }
}

void minMax::trickleDown(int index)
{
      int temp;
      int indexOfSmallest;
      int indexOfLargest;
      if(isMinNode(index))
      {
//            std::cout <<"TrickleDown on MinNode value "  << m_content[index] << " index: " <<index<<"\n";
//            std::cout <<"m_lastIndex: " << m_lastIndex << "\n";
//            printChildren(index);
            indexOfSmallest=index;
            //std::cout << "index*2-1: " << index*2-1 << "\n";
            //if((index*2-1)<=m_lastIndex)//no left child
            if(m_lastIndex<2*index)
            {
//                  std::cout << "AfterTrickleDown\n\n";
//                  levelorder();
                  return;
            }
            if((index*2+1)-1<=m_lastIndex)//yes lchild no rightChild
            {
//                  std::cout << "Do we get here?\n";
                  if(m_content[index*2]<m_content[indexOfSmallest])
                  {
                        indexOfSmallest = index*2;
                  }
            }
            if((index*2)*2-1<=m_lastIndex)//yes lc and rc no lclc
            {
                  if(m_content[index*2+1]<m_content[indexOfSmallest])
                  {
                        indexOfSmallest=index*2+1;
                  }
            }
            if((index*2)*2+1-1<=m_lastIndex)//yes lc,rc,lclc,no lcrc
            {
                  if(m_content[(index*2)*2]<m_content[indexOfSmallest])
                  {
                        indexOfSmallest=(index*2)*2;
                  }
            }
            if((index*2+1)*2-1<=m_lastIndex)
            {
                  if(m_content[(index*2)*2+1]<m_content[indexOfSmallest])
                  {
                        indexOfSmallest=(index*2)*2+1;
                  }
            }
            if(((index*2+1)*2+1-1)<=m_lastIndex)
            {
                  if(m_content[(index*2+1)*2]<m_content[indexOfSmallest])
                  {
                        indexOfSmallest=(index*2+1)*2;
                  }
            }
            if(((index*2+1)*2+1-1)<=m_lastIndex)
            {
                  if(m_content[(index*2+1)*2+1]<m_content[indexOfSmallest])
                  {
                        indexOfSmallest=(index*2+1)*2+1;
                  }
            }
            if(indexOfSmallest==index)//case where the smallest node is where we
            {//started and no swap is necessary
//                  std::cout << "after trickledown\n\n";
//                  levelorder();
                  return;
            }
            else//swap and recurse
            {
                  //std::cout << "m_content[index]: " << m_content[index] <<"\n";
                  //std::cout << "m_content[indexOfSmallest]: "<< m_content[indexOfSmallest] << "\n";
                  //std::cout << "indexOfSmallest: " << indexOfSmallest << "\n";
                  temp=m_content[index];
                  //std::cout << "temp: " << temp << "\n";
                  m_content[index]=m_content[indexOfSmallest];
                  //std::cout << "m_content[index]: " << m_content[index] << "\n";
                  m_content[indexOfSmallest]=temp;
                  //std::cout << "m_content[indexOfSmallest]: " << m_content[indexOfSmallest]<<"\n";
                  //std::cout << "after trickledown before recursion\n\n";
//                  levelorder();
                  if(index/4<=0)
                  {
                        return;
                  }
                  else
                  {
                        //std::cout << "index/4:" << index/4 << "\n";
                        trickleDown(index/4);
                        return;
                  }
            }
            levelorder();

      }
      else//maxnodeCase
      {
//            std::cout << "Trickledown on maxNode value " << m_content[index] << " index " << index << "\n";
//            printChildren(index);
            indexOfLargest=index;
            if(m_lastIndex<2*index)//no left child
            {
                  return;
            }
            if((index*2+1-1)<=m_lastIndex)//yes lchild no rightChild
            {
                  if(m_content[index*2]>m_content[indexOfLargest])
                  {
                        indexOfLargest = index*2;
                  }
            }
            if((index*2)*2-1<=m_lastIndex)//yes lc and rc no lclc
            {
                  if(m_content[index*2+1]>m_content[indexOfLargest])
                  {
                        indexOfLargest=index*2+1;
                  }
            }
            if((index*2)*2+1-1<=m_lastIndex)//yes lc,rc,lclc,no lcrc
            {
                  if(m_content[(index*2)*2]>m_content[indexOfLargest])
                  {
                        indexOfLargest=(index*2)*2;
                  }
            }
            if((index*2+1)*2-1<=m_lastIndex)
            {
                  if(m_content[(index*2)*2+1]>m_content[indexOfLargest])
                  {
                        indexOfLargest=(index*2)*2+1;
                  }
            }
            if(((index*2+1)*2+1-1)<=m_lastIndex)
            {
                  if(m_content[(index*2+1)*2]>m_content[indexOfLargest])
                  {
                        indexOfLargest=(index*2+1)*2;
                  }
            }
            if(((index*2+1)*2+1-1)<=m_lastIndex)
            {
                  if(m_content[(index*2+1)*2+1]>m_content[indexOfLargest])
                  {
                        indexOfLargest=(index*2+1)*2+1;
                  }
            }
            if(indexOfLargest==index)//case where the smallest node is where we
            {//started and no swap is necessary
                  return;
            }
            else//swap and recurse
            {
                  temp=m_content[index];
                  m_content[index]=m_content[indexOfLargest];
                  m_content[indexOfLargest]=temp;
                  if(index/4<=0)
                  {
                        return;
                  }
                  else
                  {
                        trickleDown(index/4);
                  }
            }
      //      levelorder();
      }
}

bool minMax::isMinNode(int index)
{
      return (int)log2(index)%2==0;
}

int minMax::leftChild(int index)
{
      if((index*2)<m_size)
      {
            return index*2;
      }
      else
      {
            return -1;//fail value
      }
}

int minMax::rightChild(int index)
{
      if((index*2+1)<m_size)
      {
            return index*2+1;
      }
      else
      {
            return -1;//fail value
      }
}

void minMax::printChildren(int index)
{
      if(index*2<=m_lastIndex)
      {
            std::cout << "leftChild: " << m_content[index*2] << "\n";
      }
      else
      {
            std::cout << "no left Child\n";
      }
      if(index*2+1<=m_lastIndex)
      {
            std::cout << "rightChild: " << m_content[index*2+1] << "\n";
      }
      else
      {
            std::cout << "no right child" << "\n";
      }
      if((index*2)*2<=m_lastIndex)
      {
            std::cout << "leftLeftChild: " << m_content[(index*2)*2] << "\n";
      }
      else
      {
            std::cout << "no LeftLeftChild\n";
      }
      if((index*2)*2+1<=m_lastIndex)
      {
            std::cout << "leftRightChild: " << m_content[(index*2)*2+1] << "\n";
      }
      else
      {
            std::cout << "noLeftRightChild\n";
      }
      if((index*2+1)*2<=m_lastIndex)
      {
            std::cout << "rightleftChild: " << m_content[(index*2+1)*2] << "\n";
      }
      else
      {
            std::cout << "noRightLeftChild\n";
      }
      if((index*2+1)*2+1<=m_lastIndex)
      {
            std::cout << "rightrightChild: " << m_content[(index*2+1)*2+1] << "\n\n";
      }
      else
      {
            std::cout << "noRightRight child\n\n";
      }
}
