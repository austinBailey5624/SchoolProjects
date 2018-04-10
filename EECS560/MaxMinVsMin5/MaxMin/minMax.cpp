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
      m_lastIndex=1;
      m_content[size];
      for(int i=0; i < m_size; i++)
      {
            m_content[i]=-1;
      }
}
