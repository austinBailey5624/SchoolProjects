/**
*	@file: 		HashTable.cpp
*	@author:	AustinBailey
*	@date:		9.15.2016
*/
#include "HashTable.h"
#include <iostream>
#include <fstream>
HashTable::HashTable()
{
	int temp;
	//bool tempb;
	std::ifstream file("data.txt");
	file >> m_size;
	m_hashField = new int[m_size];
	m_flagField = new bool[m_size];
	for(int i=0;i<m_size;i++)
	{
		m_hashField[i]=-1;
		m_flagField[i]=false;
	}
	while(file.good())
	{
		file >> temp;
//		std::cout << temp << "\n";
		insert(temp);
		// if(!tempb)
		// {
		// 	std::cout << "Could not add the value " << temp << " From file during initialization\n";
		// }
	}
}

HashTable::~HashTable()
{
	delete m_hashField;
	delete m_flagField;
}

bool HashTable::insert(int value)
{
	if(isFull())
	{
		std::cout << "Cannot add " << value << " because the table is full!\n";
		return false;
	}
	for(int i=0;i<m_size;i++)//this loop tries to insert the value m_size number of times
	{
		if(this->contains(value))
		{
//			std::cout << "The value " << value << " is already in the list\n";
			return false;
		}
		else if(hash(value,i))
		{
			return true;
		}
	}
	return false;
}

bool HashTable::remove(int value)
{
	if(!contains(value))
	{
		std::cout << "The value is not in the hash table";
		return false;
	}
	int x = value%m_size;
	for(int i=0;i<m_size;i++)//we will traverse a maximum of m_size number of times
	{
//		std::cout << "hash value is:" <<(x+(i*i)%m_size)  << "\n";
//		std::cout << "hash field is:" <<m_hashField[(x+(i*i))%m_size]<<"\n";
//		std::cout << "value: "<< value << "\n";
		if(m_hashField[(x+(i*i))%m_size]==value)//case where we found the value we want to remove
		{
//			std::cout << "Got here\n";
			m_hashField[(x+(i*i))%m_size]=-1;//removes the value
			m_flagField[(x+(i*i))%m_size]=true;//sets the value to true so the next removal knows there was a value here, so it doesn't stop iterating through the loop
			return true;
		}
		else if(m_hashField[(x+(i*i))%m_size]==-1&&m_flagField[(x+(i*i))%m_size]==false)
		{
				std::cout << "The value is in the hash table but we cannot find it\n";
				std::cout << "Using quadratic probing.\n";
				return false;
		}

	}

	return true;
}

void HashTable::print()
{
	for(int i=0;i<m_size;i++)
	{
		std::cout << i<< ": " << m_hashField[i] << " flag =";
		if(m_flagField[i]==false)
		{
			std::cout << " false\n";
		}
		else
		{
			std::cout << " true\n";
		}
	}
	return;
}

bool HashTable::hash(int value, int i)
{
	int x = value%m_size;//assigns x to the value that were adding squares to
	if(m_hashField[(x+(i*i))%m_size]==-1)//quadratic probing
	{
		m_hashField[(x+(i*i))%m_size]=value;
		return true;
	}
	return false;
}

bool HashTable::contains(int value)
{
	for(int i=0;i<m_size;i++)
	{
		if(m_hashField[i]==value)
		{
			return true;
		}
	}
	return false;
}

bool HashTable::isFull()
{
	for(int i=0;i<m_size;i++)
	{
		if(m_hashField[i]==-1)//case where I found an empty address so its not full
		{
			return false;
		}
	}
	return true;//I searched all the addresses and theyre all full
}
