/**
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
}

Node::Node(int value)
{
      m_left=nullptr;
      m_right=nullptr;
      m_next=nullptr;
      m_value=value;
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
