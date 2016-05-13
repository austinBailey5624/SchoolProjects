/**
*	@file: 		Node.cpp
*	@author:	Austin Bailey
*	@date:		2.5.2015
*	@purpose:	Implementation of Node Class
*/

#include "Node.h"
#include <iostream>
Node::Node()
{
	m_value = 0;
	m_next = nullptr;
}
void Node::setValue(int value) 
{
	m_value = value;
}
int Node::getValue()const
{
	return m_value;
}
void Node::setNext(Node* next)
{
	m_next=next;
}
Node* Node::getNext()
{
	return m_next;
}
