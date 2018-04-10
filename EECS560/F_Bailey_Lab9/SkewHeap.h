/**
*     @file:            SkewHeap.h
*     @author:          Austin Bailey
*     @date:            11/7/16
*/

#ifndef SKEWHEAP_H
#define SKEWHEAP_H
#include <fstream>
#include <iostream>
#include "Node.h"
#include "Queue.h"

class SkewHeap
{
public:
      SkewHeap();
      ~SkewHeap();
      void deleteHelper(Node* subtree);
      Node* merge(Node* left, Node* right);
      Node* insert(Node* base, int value);
      void deleteMin();
      void levelOrder(Node* root);
      void preOrder(Node* subtree);
      void inOrder(Node* subtree);
      Node* getRoot();
      void setRoot(Node* root);
private:
      Node* m_root;

};
#endif
