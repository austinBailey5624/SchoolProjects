/*
*     @file       minMax.h
*     @author     Austin bailey
*     @date       10.22.2016
*/
#ifndef minMax_h
#define minMax_h

class minMax
{
public:
      minMax(int size);
      ~minMax();
      void build();
      void insert(int value);
      void remove(int value);
      void deletemin();
      void deletemax();
      void levelorder();
private:
      int m_size;
      int m_lastIndex;
      int m_content[];
};
