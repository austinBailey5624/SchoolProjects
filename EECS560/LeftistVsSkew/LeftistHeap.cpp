/**
*     @file:            LeftistHeap.cpp
*     @author:          Austin Bailey
*     @date:            11/4/16
*/
#include "LeftistHeap.h"

LeftistHeap::LeftistHeap(bool build)
{
      if(!build)
      {
            m_root=nullptr;
            return;
      }
      m_root=nullptr;
      std::ifstream file("data.txt");
      int temp;
      while(true)
      {
            file >> temp;
						if(file.eof())
						{
									break;
						}
			this->m_root=insert(this->m_root,temp);
      }
      return;
}

LeftistHeap::~LeftistHeap()
{
      deleteHelper(this->getRoot());
}

void LeftistHeap::deleteHelper(Node* subtree)
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

Node* LeftistHeap::merge(Node* Left, Node* Right)
{     //terminating condigions
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

            // //recurses down tree
            Left->setRight(merge(Left->getRight(),Right));
            if(Left->getLeft()==nullptr&&Left->getRight()==nullptr)
            {
                  return Left;
            }
            if(Left->getLeft()==nullptr)
            {
                  Left->setLeft(Left->getRight());
                  Left->setRight(nullptr);
                  return Left;
                  //eturn Left;
            }
            if(Left->getRight()==nullptr)
            {
                  return Left;
            }
            //TODO - finish writing stuff for the other case
            //
            // //case where we should swap
            this->computeRank(Left);
            if(Left->getLeft()!=nullptr)
            {
                  this->computeRank(Left->getLeft());//->computeRank();
            }
            if(Left->getRight()!=nullptr)
            {
                  this->computeRank(Left->getRight());//->computeRank();
            }
            if(Left->getLeft()->getRank() < Left->getRight()->getRank())//swap
            {
                  Node* temp = Left->getLeft();
                  Left->setLeft(Left->getRight());
                  Left->setRight(temp);
            }
            return Left;
      }
      else
      {
            Right->setRight(merge(Right->getRight(),Left));

            if(Right->getLeft()==nullptr&&Right->getRight()==nullptr)
            {
                  return Right;
            }
            if(Right->getLeft()==nullptr)
            {
                  Right->setLeft(Right->getRight());
                  Right->setRight(nullptr);
                  return Right;
            }
            if(Left->getRight()==nullptr)
            {
                  return Left;
            }


            this->computeRank(Right);
            if(Right->getLeft()!=nullptr)
            {
                  this->computeRank(Left->getLeft());//->computeRank();
            }
            if(Right->getRight()!=nullptr)
            {
                  this->computeRank(Left->getRight());//->computeRank();
            }
            if(Right->getLeft()->getRank() < Right->getRight()->getRank())//swap
            {
                  Node* temp = Right->getLeft();
                  Right->setLeft(Right->getRight());
                  Right->setRight(temp);
            }
            return Right;
      }
}

Node* LeftistHeap::insert(Node* base, int value)
{
      Node* inserter = new Node();
      inserter->setValue(value);
      return(merge(base, inserter));
}

void LeftistHeap::deleteMin()
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

void LeftistHeap::levelOrder(Node* root)
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

void LeftistHeap::preOrder(Node* subtree)
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

void LeftistHeap::inOrder(Node* subtree)
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

Node* LeftistHeap::getRoot()
{
      return m_root;
}

void LeftistHeap::setRoot(Node* root)
{
      m_root=root;
}

void LeftistHeap::computeRank(Node* computer)
{
      if(computer->getLeft()==nullptr||computer->getRight()==nullptr)
      {
            //return 1;
            computer->setRank(1);
            return;
      }
      if(computer->getLeft()->getRank()==computer->getRight()->getRank())
      {
            computer->setRank(computer->getLeft()->getRank()+1);
            return;
      }
      if(computer->getLeft()->getRank()<computer->getRight()->getRank())
      {
            computer->setRank(computer->getLeft()->getRank());
            return;
      }
      computer->setRank(computer->getRight()->getRank());
}
