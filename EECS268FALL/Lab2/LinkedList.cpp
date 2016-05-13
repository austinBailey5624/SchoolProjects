/**
*	@file		LinkedList.cpp
*	@author		Austin Bailey
*	@date		9/9/2015
*	@purpose	implementaion file for linked list class
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
		this->removeFront();
	}
}

bool LinkedList::isEmpty() const
{
	return m_front==nullptr;
}

int LinkedList::size()const
{
	return m_size;
}

bool LinkedList::search(int value) const
{
	if(m_front==nullptr)
	{
		std::cout << "Sorry, we couldn't find your value because the list is empty\n";
		return false;
	}
	Node* temp=m_front;
	while(temp!=nullptr)
	{
		if(temp->getValue()==value)
		{
			return true;
		}
		temp=temp->getNext();
	}

	return false;
}

void LinkedList::printList() const
{
	if(m_front==nullptr)
	{
		std::cout << "";
		return;
	}
	Node* temp = m_front;
	while(temp!=nullptr)
	{
		std::cout << temp->getValue() << " ";
		temp=temp->getNext();
	}
	std::cout << "\n";
}

void LinkedList::addBack(int value)
{
	Node* NewBack=new Node(value);		//New Node to be added

	if(m_front==nullptr)			//if handles empty case
	{
		m_front=NewBack;
		m_size++;
		return;
	}

	Node* OldBack = m_front;		//this block handles nonempty cas
	while(OldBack->getNext()!=nullptr)	//while loop makes OldBack the last Node
	{
		OldBack=OldBack->getNext();
	}
	OldBack->setNext(NewBack);		//Sets newBack to the last position
	m_size++;
}

void LinkedList::addFront(int value)
{
	Node* newFront = new Node(value);	//New Node to be added
	if(m_front==nullptr)			//if handles empty case
	{
		m_front = newFront;
		m_size++;
		return;
	}
//	Node* temp=m_front;			
//	m_front= newFront;
//	newFront->setNext(temp);
	newFront->setNext(m_front);
	m_front=newFront;
	m_size++;
}

bool LinkedList::removeBack()
{
	if(m_front==nullptr)			//Handles Empty case
	{
		return false;
	}

	else if(m_size==1)			//Handles One node case
	{
		delete m_front;
		m_front=nullptr;
		m_size--;
		return true;
	}

	Node* back = m_front;			//Handles Greater than one case
	while(back->getNext()->getNext()!=nullptr)//loop ensures that back is looking at next to end
	{
		back=back->getNext();
	}
	delete back->getNext();
	back->setNext(nullptr);
	m_size--;
	return true;
}

bool LinkedList::removeFront()
{
	if(m_front==nullptr)			//handles empty case
	{	
		return false;
	}

	else if(m_size==1)
	{
		delete m_front;
		m_front=nullptr;
		m_size--;
		return true;
	}

	Node* newFront =m_front->getNext();
	delete m_front;
	m_front = newFront;
	m_size--;
	return true;
}
