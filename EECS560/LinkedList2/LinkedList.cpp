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
	//TODO: implement search to check if the value is already in the list
	if(find(value))//handles the case that the value is already in the array
	{
			return;
	}
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

bool LinkedList::erase(int value)//returns true if the value is deleted false else
{
	if(m_front==nullptr)
	{
		std::cout << "The list is empty\n";
		return false;
	}
	//first use find() to determine if its in the list -if not return false
	if(!find(value))
	{
		std::cout << "The value is not in the list!\n";
		return false;
	}


	Node* temp=m_front;
	Node* temp2 =m_front;//looks at node before delete
	Node* temp3;//looks at node after delete

	//front of list case-size==1
	if(m_front->getValue()==value&&m_front->getNext()==nullptr)
	{
			delete m_front;
			return true;
	}
	else if(m_front->getValue()==value)
	{
		temp=m_front->getNext();
		delete m_front;
		m_front=temp;
		return true;
	}

	//middle of list case
	while(temp->getNext()!=nullptr)
	{
		if(temp->getValue()==value)
		{
				temp3=temp->getNext();
				delete temp;
				temp2->setNext(temp3);
				return true;
		}
		temp2=temp;
		temp=temp->getNext();
	}
	if(temp->getNext()==nullptr)
	{
		delete temp;
		temp2->setNext(nullptr);
		return true;
	}
	return false;
	//end of list case
	//then delete the node
}

bool LinkedList::find(int value)
{
	if(m_front==nullptr)
	{
//		std::cout << "The list is empty.";
		return false;
	}
	Node* temp=m_front;
	while(temp->getNext()!=nullptr)
	{
		if(temp->getValue()==value)
		{
			return true;
		}
		temp=temp->getNext();
	}
	if(temp->getValue()==value)
	{
		return true;
	}
	return false;


	return 0; //temporary to satisfy complier
}

void LinkedList::reverse()
{
	if(m_front==nullptr)//empty edge case
	{
		return;
	}
	else if(m_front->getNext()==nullptr)//single element edge case
	{
		return;
	}
	int first=0;
	int last=0;
	Node* temp=m_front;
	while(temp->getNext()!=nullptr)
	{
		last++;
		temp=temp->getNext();
	}
	reverseHelper(first,last);
}

void LinkedList::reverseHelper(int first, int last)
{

	Node* temp=m_front;
	Node* temp2=m_front;
	Node* temp3= new Node();
	for(int i=0; i<first;i++)
	{
			temp=temp->getNext();
	}

	for(int i=0; i<last;i++)
	{
		temp2=temp2->getNext();
	}
//	std::cout << "\nbefore transformation: ";
	//std::cout << "\nfirst: " << first << "\nlast: " << last << "\n";
//	LinkedList::print();
	temp3->setValue(temp->getValue());
	temp->setValue(temp2->getValue());
	temp2->setValue(temp3->getValue());
	first++;
	last--;
	if(first>=last)
	{
		return;
	}
	//std::cout << "\nafter transformation:  ";
	//	LinkedList::print();
	reverseHelper(first, last);
}

void LinkedList::concatenate(std::ifstream& file)
{

	if(file.good())
	{
		int temp=-17345689;
		file >> temp;//theres this weird bug where this line doesn't execute at the end, hence the weird number workaround
		if(temp!=-17345689)
		{
			insert(temp);
		}
		concatenate(file);
	}
	else
	{
		return;
	}
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
	while(file.good())
	{
			file >> temp;
			insert(temp);
	}
}
