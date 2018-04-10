/**
*	@file: 		Node.cpp
*	@author:	Austin Bailey
*	@date:		8.26.2016
*/

#include "Node.h"

Node::Node()
{
	m_value=0;
	m_next=nullptr;
}

Node::~Node()
{

}

Node* Node::getNext()
{
	return m_next;
}

int Node::getValue()
{
	return m_value;
}

void Node::setNext(Node* next)
{
	m_next=next;
}

void Node::setValue(int value)
{
	m_value=value;
}
