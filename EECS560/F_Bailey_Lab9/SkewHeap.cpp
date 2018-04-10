/**
*     @file       Skewheap.h
*     @author     Austin Bailey
*     @date       11.7.2016
**/
#include "SkewHeap.h"
SkewHeap::SkewHeap()
{
      m_root=nullptr;
      // std::ifstream file("data.txt");//commented out for timing implementation
      // int temp;
      // while(true)
      // {
      //       file >> temp;
      //       if(file.eof())
      //       {
      //             break;
      //       }
      //       this->m_root=insert(this->m_root, temp);
      // }
      return;
}

SkewHeap::~SkewHeap()
{
      deleteHelper(this->getRoot());
}

void SkewHeap::deleteHelper(Node* subtree)
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

Node* SkewHeap::merge(Node* Left, Node* Right)
{
      if(Left==nullptr&&Right==nullptr)
      {
            return nullptr;
      }
      else if(Left==nullptr)
      {
            return Right;
      }
      else if(Right==nullptr)
      {
            return Left;
      }

      if(Left->getValue()<=Right->getValue())
      {
            if(Left->getRight()==nullptr && Left->getLeft()==nullptr)
            {
                  Left->setRight(Right);
            }
            else if(Left->getRight()==nullptr)
            {
                  Left->setRight(merge(Left->getLeft(),Right));

            }
            else if(Left->getLeft()==nullptr)
            {
                  Node* temp = Left->getRight();
                  Left->setRight(Right);
                  Left->setLeft(temp);
            }
            else// if(Left->getLeft()==nullptr)
            {
                  Node* temp = Left->getRight();
                  Left->setRight(merge(Left->getLeft(),Right));
                  Left->setLeft(temp);
            }
            return Left;
      }
      else
      {
            if(Right->getRight()==nullptr && Right->getLeft()==nullptr)
            {
                  Right->setRight(Left);
            }
            else if(Right->getRight()==nullptr)
            {
                  Right->setRight(merge(Right->getLeft(),Left));
            }
            else if(Right->getLeft()==nullptr)
            {
                  Node* temp = Right->getRight();
                  Right->setRight(Left);
                  Right->setLeft(temp);
            }
            else
            {
                  Node* temp = Right->getRight();
                  Right->setRight(merge(Right->getLeft(),Left));
                  Right->setLeft(temp);
            }
            return Right;
      }
}

Node* SkewHeap::insert(Node* base, int value)
{
      Node* inserter = new Node();
      inserter->setValue(value);
      return(merge(base,inserter));
}

void SkewHeap::deleteMin()
{
      if(this->getRoot()==nullptr)
      {
            return;
      }
      if(  (this->getRoot()->getLeft()==nullptr) && (this->getRoot()->getRight()==nullptr))
      {
            delete(this->getRoot());
            return;
      }
      if(this->getRoot()->getLeft()==nullptr)
      {
            Node* temp= this->getRoot()->getRight();
            delete(this->getRoot());
            this->setRoot(temp);
            return;
      }
      if(this->getRoot()->getRight()==nullptr)
      {
            Node* temp = this->getRoot()->getLeft();
            delete(this->getRoot());
            this->setRoot(temp);
      }
      Node* tempLeft = this->getRoot()->getLeft();
      Node* tempRight = this->getRoot()->getRight();
      delete(this->getRoot());
      this->setRoot(merge(tempLeft,tempRight));
}

void SkewHeap::levelOrder(Node* root)
{
            int curLevel=1;
            Queue* myQueue = new Queue();
            Node* temp;
            if(root==nullptr)
            {
                  return;
            }
            root->m_level=0;
            myQueue->enqueue(root);
            while(!(myQueue->isEmpty()))
            {
                  temp=myQueue->dequeue();
                  temp->setNext(nullptr);
                  if(temp->m_level==curLevel)
                  {
                        std::cout << "\n";
                        curLevel++;
                  }
                  std::cout << temp->getValue() << " ";
                  if(temp->getLeft()!=nullptr)
                  {
                        temp->getLeft()->m_level=temp->m_level+1;
                        myQueue->enqueue(temp->getLeft());
                  }
                  if(temp->getRight()!=nullptr)
                  {
                        temp->getRight()->m_level=temp->m_level+1;
                        myQueue->enqueue(temp->getRight());
                  }
            }
            return;
}

void SkewHeap::preOrder(Node* subtree)
{
      if(subtree==nullptr)//takes care of the empty case
      {
            return;
      }
      std::cout << subtree->getValue() << " ";
      if(subtree->getLeft()!=nullptr)//checks to make sure the left child is not nullptr
      {//which is the terminating condition of the recursion
            preOrder(subtree->getLeft());
      }
      if(subtree->getRight()!=nullptr)
      {
            preOrder(subtree->getRight());
      }
      return;
}

void SkewHeap::inOrder(Node* subtree)
{
      if(subtree->getLeft()!=nullptr)
      {
            inOrder(subtree->getLeft());
      }
      std::cout << subtree->getValue() << " ";
      if(subtree->getRight()!=nullptr)
      {
            inOrder(subtree->getRight());
      }

      return;
}

Node* SkewHeap::getRoot()
{
      return m_root;
}

void SkewHeap::setRoot(Node* root)
{
      m_root=root;
}
