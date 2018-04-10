/**
*     @file:            BinarySearchTree.h
*     @author:          Austin Bailey
*     @date:            9/20/2016
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"
#include "Queue.h"
#include <iostream>
#include <fstream>

class BinarySearchTree
{
      public:
            BinarySearchTree();
            ~BinarySearchTree();
            void deleteHelper(Node* subtree);
            bool insert(int value, Node* subtree);
//            bool insertBranch(int value, Node* Subtree);
            bool remove(int value, Node* subtree);
            Node* search(int value,Node* subtree);
            bool deleteMin();
            bool deleteMax();
            void preorder(Node* subtree);
            void inorder(Node* subtree);
            void levelorder(Node* root);
//            void levelorderHelper(Queue* myQueue);

            Node* getRoot();
      private:
            Node* m_root;
};
#endif
