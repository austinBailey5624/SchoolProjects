/**
*     @file:            LeftistHeap.h
*     @author:          Austin Bailey
*     @date:            11/4/16
*/

#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H
#include <fstream>
#include <iostream>
#include "Node.h"
#include "Queue.h"

class LeftistHeap
{
public:
      LeftistHeap(bool build);
      ~LeftistHeap();
      void deleteHelper(Node* subtree);
      Node* merge(Node* left, Node* right);
      Node* insert(Node* base, int value);
      void deleteMin();
      void levelOrder(Node* root);
      void preOrder(Node* subtree);
      void inOrder(Node* subtree);
      Node* getRoot();
      void setRoot (Node* root);
      void computeRank(Node* computer);
private:
      Node* m_root;
};

#endif
