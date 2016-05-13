/**
*	@file:		Node.cpp
*	@author:	Austin Bailey
*	@date:		9/11/2015
*	@purpose:	implementation file for the Node Class
**/
#include "Node.h"

Node::Node()	//constructor
{
	m_value=0;
	m_next=nullptr;
}

Node::Node(int value)//constructor
{
	m_value=value;
	m_next=nullptr;
}
void Node::setValue(int value)	//setter
{
	m_value = value;
}

int Node::getValue() const	//getter
{
	return m_value;
}

void Node::setNext(Node* prev)	//setter
{
	m_next=prev;
}

Node* Node::getNext() const	//getter
{
	return m_next;
}
