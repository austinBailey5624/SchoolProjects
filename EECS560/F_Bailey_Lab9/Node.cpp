/**
*     @file:            Node.cpp
*     @author:          Austin Bailey
*     @date:            11/4/16
*/
/** copied From: (then altered)
*     @file:           Node.cpp
*     @author:          Austin Bailey
*     @date:            9.20.2016
*/
#include "Node.h"
Node::Node()
{
      m_left=nullptr;
      m_right=nullptr;
      m_next=nullptr;
      m_value=0;
      m_rank=1;
      m_level=0;
}

Node::Node(int value)
{
      m_left=nullptr;
      m_right=nullptr;
      m_next=nullptr;
      m_value=value;
      m_rank=1;
      m_level=0;
}
Node::~Node()
{

}

int Node::getValue()const
{
      return m_value;
}

void Node::setValue(int value)
{
      m_value = value;
}

Node* Node::getLeft()const
{
      return m_left;
}

void Node::setLeft(Node* left)
{
      m_left=left;
}

Node* Node::getRight()const
{
      return m_right;
}

void Node::setRight(Node* right)
{
      m_right = right;
}

Node* Node::getNext()const
{
      return m_next;
}

void Node::setNext(Node* next)
{
      m_next =  next;
}

int Node::getRank()
{
      // if(this==nullptr)
      // {
      //       return 0;//should be 1 maybe?
      // }
      // if(this->m_left==nullptr&&this->m_right==nullptr)
      // {
      //       return 1;
      // }
      // if(this->m_left->getRank()==this->m_right->getRank())
      // {
      //       return m_left->getRank()+1;
      // }
      // if(m_left->getRank()<m_right->getRank())
      // {
      //       return m_left->getRank();
      // }
      // return m_right->getRank();
      return m_rank;

}

void Node::setRank(int rank)
{
      m_rank = rank;
}
