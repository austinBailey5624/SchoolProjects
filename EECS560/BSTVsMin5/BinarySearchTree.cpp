/**
*     @file:            BinarySearchTree.cpp
*     @author:          Austin Bailey
*     @date:            9/20/2016
*/

#include "Node.h"
//#include "Queue.h"
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"
BinarySearchTree::BinarySearchTree()
{
      int temp;
      m_root=nullptr;
      std::ifstream file("data.txt");
      while(file.good())
      {
            file >> temp;
            insert(temp,m_root);
      }

}

BinarySearchTree::~BinarySearchTree()
{
      //will delete in postorder recursively using deleteHelper
      deleteHelper(m_root);
}

void BinarySearchTree::deleteHelper(Node* subtree)
{
      if(subtree->getLeft()!=nullptr)
      {
            deleteHelper(subtree->getLeft());
      }
      if(subtree->getRight()!=nullptr)
      {
            deleteHelper(subtree->getRight());
      }
      delete subtree;
}

bool BinarySearchTree::insert(int value,Node* subtree)
{
      if(subtree==nullptr)//checks to make sure the subtree is not empty, ifso populates
      {
            m_root=new Node(value);
            return true;
      }
      if(value<subtree->getValue())//handles left tree subcase
      {
            if(subtree->getLeft()==nullptr)//if the node does not have a left child
            {//insert the new node as that child
                  Node* temp = new Node(value);
                  subtree->setLeft(temp);
                  return true;
            }
            else// if the node does have a left child
            {//recurse down that branch
                  insert(value, subtree->getLeft());
            }
      }
      else if(value>=subtree->getValue())
      {
            if(subtree->getRight()==nullptr)
            {
                  Node* temp = new Node(value);
                  subtree->setRight(temp);
                  return true;
            }
            else
            {
                  insert(value, subtree->getRight());
            }
      }
      return true;
}
// bool BinarySeachTree::insertBranch(int value, Node* subtree)
// {
//
// }
bool BinarySearchTree::remove(int value, Node* subtree)
{
//      std::cout << "Got here\n";
      if(subtree->getValue()==value)//handles the case where we are in the removed Node
      {
            std::cout << "GotHere2\n";
            if(subtree->getRight()==nullptr && subtree->getLeft()==nullptr)
            {
                  std::cout << "GotHere3\n";
                  std::cout << "subtree value = " << subtree->getValue() << "\n";
                  delete subtree;
                  subtree=nullptr;
                  std::cout << "Do not get here\n";
                  return true;
            }//hanldes case where removed node only has left subtree
            else if(subtree->getRight()==nullptr && subtree->getLeft()!=nullptr)
            {
                  std::cout << "GotHere4\n";
                  Node* temp = subtree->getLeft();//creates a temporary pointer to look at the left child
                  delete subtree; //deletes the bad node
                  subtree=temp;//sets the old nodes left child to its current node
                  return true;
            }//handles case where removed node only has right subtree
            else if(subtree->getRight()!=nullptr && subtree->getLeft()==nullptr)
            {
                  std::cout << "GotHere5\n";
                  Node* temp = subtree->getRight();
                  delete subtree;
                  subtree = temp;
                  return true;
            }//handles case with two children
            else if(subtree->getRight()!=nullptr && subtree->getLeft()!=nullptr)
            {
                  std::cout << "Gothere6\n";
                  Node* temp=subtree->getRight();
                  while(temp->getLeft()!=nullptr)//transverses down the left subtrees
                  {//of the right node until it reaches the last one
                  //the node it ends up set to should be the smallest value of the
                  //right subtree
                        temp=temp->getLeft();
                  }
                  Node* temp2= new Node(temp->getValue());//creates the node that will replace
                  //the removed node
                  remove(temp->getValue(),temp);//removes the replacing node
                  delete subtree;
                  subtree = temp2;
                  return true;
            }
            std::cout << "Gothere7\n";
      }
      if(value<subtree->getValue())//transverses down left subtree
      {
            if(subtree->getLeft()!=nullptr)//checks to make sure that the subtree can
            {//be transversed
                  remove(value, subtree->getLeft());
            }
            else
            {
                  return false;//because the value does not exist in the tree
            }
      }
      if(value>subtree->getValue())
      {
            if(subtree->getRight()!=nullptr)
            {
                              remove(value, subtree->getRight());
            }
            else
            {
                  return false;
            }

      }
      return false;//handles case where BST does not contain the value
}

Node* BinarySearchTree::search(int value, Node* subtree)
{
      if(subtree->getValue()==value)//if the subtree contains the value specified
      {//then return the subtree-terminating condition for recursion
            return subtree;
      }
      else if(subtree->getValue()>value)
      {
            if(subtree->getRight()!=nullptr)//checks to make sure the node can be accessed
            {
                  search(value,subtree->getRight());
            }
            else//if the node doesn't exist, then the value is not in the tree
            {
                  return nullptr;
            }
      }
      else if(subtree->getValue()<value)
      {
            if(subtree->getLeft()!=nullptr)
            {
                  search(value,subtree->getLeft());
            }
            else
            {
                  return nullptr;
            }
      }
      return nullptr;
}

bool BinarySearchTree::deleteMin()
{
      if(m_root==nullptr)//if theres nothing to delete ,return false
      {
            return false;
      }
      if(m_root->getLeft()==nullptr)//handles the case where m_root is the smallest
      {//value
            remove(m_root->getValue(),m_root);
            return true;
      }
      Node* temp=m_root;
      while(temp->getLeft()!=nullptr)//sets temp to the smallest value node
      {
            temp=temp->getLeft();
      }
      remove(temp->getValue(),temp);
      return true;
}

bool BinarySearchTree::deleteMax()
{
      if(m_root==nullptr)
      {
            return false;
      }
      if(m_root->getRight()==nullptr)//if the root doesnt have a right node, its the
      {//largest node and needs to be removed
//            std::cout << "is this the issue?1\n";
            remove(m_root->getValue(),m_root);
//            std::cout << "this is not the issue1\n";
            return true;
      }
      Node* temp=m_root;
//      std::cout << "is this the issue?2\n";
      while(temp->getRight()!=nullptr)
      {
//            std::cout << "temp = " << temp->getValue() << "\n";
//            std::cout << "tempRight = " << temp->getRight()->getValue() <<"\n";
            temp=temp->getRight();
      }
//      std::cout << "This is not the issue2\n";
      remove(temp->getValue(),temp);
      //remove(temp->getValue(),m_root);
      return true;
}

void BinarySearchTree::preorder(Node* subtree)
{
      if(subtree==nullptr)//takes care of the empty case
      {
            return;
      }
      std::cout << subtree->getValue() << " ";
      if(subtree->getLeft()!=nullptr)//checks to make sure the left child is not nullptr
      {//which is the terminating condition of the recursion
            preorder(subtree->getLeft());
      }
      if(subtree->getRight()!=nullptr)
      {
            preorder(subtree->getRight());
      }
      return;
}

void BinarySearchTree::inorder(Node* subtree)
{
//      std::cout << "Inorder\n";
      if(subtree->getLeft()!=nullptr)
      {
            inorder(subtree->getLeft());
      }
      std::cout << subtree->getValue() << " ";
      if(subtree->getRight()!=nullptr)
      {
            inorder(subtree->getRight());
      }

      return;
}

void BinarySearchTree::levelorder(Node* root)
{
//      std::cout <<"Here -1\n";
      Queue* myQueue = new Queue();
//      std::cout << "Reached Levelorder function\n";
      if(root==nullptr)
      {
            return;
      }
      myQueue->enqueue(root);
//      std::cout << "Successuflly enqueued root\n";
//      Node* temp;
      while(!(myQueue->isEmpty()))
      {
            Node* temp=myQueue->dequeue();
            temp->setNext(nullptr);
            std::cout << temp->getValue() << " ";
            if(temp->getLeft()!=nullptr)
            {
                  myQueue->enqueue(temp->getLeft());
            }
            if(temp->getRight()!=nullptr)
            {
                  myQueue->enqueue(temp->getRight());
            }
//            delete temp;
      }
      //levelorderHelper(myQueue);
//      std::cout << "levelOrder\n";
//      delete myQueue;
      return;
}

// void BinarySearchTree::levelorderHelper(Queue* myQueue)
// {
//
//       if(myQueue->isEmpty())//checks to see if the queue is empty if so returns
//       {
//             return;
//       }
//       Node* temp=myQueue->dequeue();//selects the first item from the queue to work with
//       std::cout << temp->getValue() << " ";//prints the value of the node
//       if(temp->getLeft()!=nullptr)//checks to see if we can enqueue the left child of temp
//       {
//             myQueue->enqueue(temp->getLeft());//equeues the left child of temp
//       }
//       if(temp->getRight()!=nullptr)
//       {
//             myQueue->enqueue(temp->getRight());
//       }
// //      delete temp;
// //      levelorderHelper(myQueue);
// /**      if(myQueue->getFirst()==nullptr)//if queue is empty return
//       {
//             return;
//       }
//       if(myQueue->getFirst()->getLeft()!=nullptr)//handles case where the first part of the queue has a left pointer
//       {//adds the left pointer to the queue if it exists
//             std::cout << "NQ: " << myQueue->getFirst()->getLeft() << "\n";
//             myQueue->enqueue(myQueue->getFirst()->getLeft());
//       }
//       if(myQueue->getFirst()->getRight()!=nullptr)
//       {
//             std::cout << "NQ: " << myQueue->getFirst()->getRight() << "\n";
//             myQueue->enqueue(myQueue->getFirst()->getRight());
//       }
//       Node* temp = myQueue->dequeue();
//       std::cout << temp->getValue() << " ";
//       levelorderHelper(myQueue);
// */
// }

Node* BinarySearchTree::getRoot()
{
      return m_root;
}
