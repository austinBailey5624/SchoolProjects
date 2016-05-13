/**
*	@file: 		LinkedList.h
*	@author:	Austin Bailey
*	@date:		2.5.2015
*	@purpose:	Header file for Linked List Class
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 
#include <iostream>
#include <string>
#include "Node.h"

class LinkedList
{
	public:
	/**
	* @pre None
	* @post Creates and initalizes a LinkedList instance
	* @return Initialized LinkedList with m_front set to nullptr and m_size set to zero
	*/
	LinkedList();

	/**
	* @pre instance of LinkedList
	* @post Destroys LinkedList
	* @return empty feeling in the pit of your soul when you have destroyed your loved creation
	*/
	~LinkedList();

	/**
	* @pre None
	* @post const; no change to variables
	* @return true if List is empty, false otherwise
	*/
	bool isEmpty() const;

	/**
	* @pre instance of LinkedList
	* @post const; no change to variables
	* @return size of LinkedList (number of Nodes)
	*/
	int size() const;

	/**
	* @pre instance of LinkedList
	* @post const; no change to variables
	* @return true if value is in list, false otherwise
	*/
	bool search(int value) const;

	/**
	* @pre instance of LinkedList
	* @post const; no change to variables
	* @return void
	*/
	void printList() const;

	/**
	* @pre instance of LinkedList
	* @post adds node of int value to front
	* @return void
	*/
	void addBack(int value);

	/**
	* @pre None
	* @post Creates and initalizes a Node instance
	* @return Initialized Node with m_value set to zero and m_next set to nullptr
	*/
	void addFront(int value);

	/**
	* @pre instance of LinkedList
	* @post removes value at back from list
	* @return true if element was removed, false if empty
	*/
	bool removeBack();

	/**
	* @pre instance of LinkedList
	* @post removes value from front of list
	* @return true if element was removed,
	*/
	bool removeFront();
	private:
	Node* m_front;
	int m_size;
};
#endif
