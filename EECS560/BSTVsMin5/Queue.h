/**
 *    @file:            queue.h
 *    @author:          Austin Bailey
 *    @date:            9.23.2016
 *    @purpose:         needed for the implementation of the levelorder print
*/

#include "Node.h"
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
public:
      Queue();
      ~Queue();
      void enqueue(Node* last);
      bool isEmpty();
      Node* dequeue();
      Node* getFirst()const;
private:
      Node* m_first;
};
#endif
