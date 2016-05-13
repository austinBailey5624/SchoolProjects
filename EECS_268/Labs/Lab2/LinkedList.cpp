/**
*	@file: 		LinkedList.cpp
*	@author:	Austin Bailey
*	@date:		2.5.2015
*	@purpose:	implementation file for LinkedList class
*/

#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_front=nullptr;
	m_size=0;
}
LinkedList::~LinkedList()
{
	while(m_front!=nullptr)
	{
		removeFront();
	}
}
bool LinkedList::isEmpty()const
{
	return(m_front==nullptr);
}
int LinkedList::size()const
{
	return m_size;
}
bool LinkedList::search(int value)const
{
	if(this->m_front==nullptr)
	{
		std::cout << "List Empty.";	
		return false;
	}
	Node* tempNode = new Node();
	while(tempNode!=nullptr)
	{
		if(tempNode->getValue()==value)
		{
			return true;
		}
		tempNode=tempNode->getNext();
	}
	return false;
}
void LinkedList::printList() const
{
	if(this->m_front==nullptr)
	{
		std::cout << "List Empty.";
		return;
	}
	Node* tempNode = new Node();
	tempNode=(this->m_front);
	while(tempNode!=nullptr)
	{
		std::cout << tempNode->getValue() << " ";
		tempNode=(tempNode->getNext());
	}
}
void LinkedList::addBack(int value)
{
	if(m_size==0)
	{
		Node* tempNode3 = new Node();
		tempNode3->setValue(value);
		this->m_front=tempNode3;
		m_size++;
		return;
	}
	Node* tempNode = new Node();
	tempNode=this->m_front;
	while(tempNode->getNext()!=nullptr)
	{
		tempNode=tempNode->getNext();
	}
	Node* tempNode2 = new Node();
	tempNode2->setValue(value);
	tempNode2->setNext(nullptr);
	tempNode->setNext(tempNode2);
	m_size++;
	return;
}
void LinkedList::addFront(int value)
{
	Node* tempNode=new Node();
	tempNode->setValue(value);
	tempNode->setNext(this->m_front);
	this->m_front = tempNode;
	m_size++;
	return;
}
bool LinkedList::removeBack()
{
	if(this->isEmpty())//handles empty case
	{
		return false;
	}
	//handles single node case
	else if(size()==1)
	{
		Node* tempNode2 = new Node;
		tempNode2 = m_front->getNext();
		delete m_front;
		m_front = tempNode2;
		m_size--;
		return true;
	}
	//Handles cases with more than one node
	Node* tempNode = new Node();
	tempNode=m_front;
	Node* tempNode2 = new Node();
	while(tempNode->getNext()->getNext()!=nullptr)
	{
		tempNode=tempNode->getNext();
	}
	tempNode2 = tempNode->getNext();
	tempNode->setNext(nullptr);
	delete tempNode2;

	return true;

}
bool LinkedList::removeFront()
{
	if(this->isEmpty())
	{
		return false;
	}
	Node* tempNode = new Node();
	tempNode=m_front;
	tempNode=tempNode->getNext();
	delete m_front;
	m_front = tempNode;
	m_size--;
	return true;
}
