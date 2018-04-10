/**
*	@file:		LinkedList.cpp
*	@author:	Austin Bailey
*	@date:		8/29/2016
*/

#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_front=nullptr;
}
LinkedList::~LinkedList()
{
	Node* temp;
	while(m_front->getNext()!=nullptr)
	{
		temp=m_front->getNext();
		delete m_front;
		m_front=temp;
	}
	if(m_front!=nullptr)
	{
		delete m_front;
	}
}

void LinkedList::insert(int value)
{
	Node* temp=new Node();
	temp->setValue(value);
	temp->setNext(nullptr);
	
	if(m_front==nullptr)//edge case where list is empty
	{
		m_front=temp;
		return;
	}
	Node* temp2;
	temp2=m_front;
	while(temp2->getNext()!=nullptr)
	{
		temp2=temp2->getNext();
	}
	temp2->setNext(temp);
}

void LinkedList::print()
{
	if(m_front==nullptr)
	{
		std::cout << "The list is empty";
		return;
	}
	Node* temp;
	temp=m_front;
	while(temp->getNext()!=nullptr)
	{
		std::cout << temp->getValue();
		std::cout << " ";
		temp=temp->getNext();
	}
	std::cout << temp->getValue();
	std::cout << " \n";
}

Node* LinkedList::getFront()const
{
	return m_front;
}

void LinkedList::setFront(Node* front)
{
	m_front=front;
}

void LinkedList::populateFromFile()
{
	int temp;
	std::ifstream file("data.txt");
	if(file.good())
	{
		for(int i=0; i<11;i++)
		{
			file >> temp;
			insert(temp);		
		}
	}
//	insert(17);
//	insert(19);
//	insert(11);
//	insert(0);
//	insert(3);
//	insert(5);
//	insert(8);
//	insert(13);
//	insert(21);
//	insert(37);
//	insert(55);
}


