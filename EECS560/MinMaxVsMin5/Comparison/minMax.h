/*
*     @file       minMax.h
*     @author     Austin bailey
*     @date       10.22.2016
*/
#ifndef minMax_h
#define minMax_h

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>//for log2
class minMax
{
public:
      minMax(int size);
      ~minMax();
      void build();
      void insert(int value);
//      void remove(int value);
      void deletemin();
      void deletemax();
      void levelorder();
      bool isMinNode(int index);
      void bubbleUp(int index);
      void trickleDown(int index);
      int leftChild(int index);
      int rightChild(int index);
      void printChildren(int index);
private:
      int m_size;
      int m_lastIndex;
      int* m_content;
};
#endif
