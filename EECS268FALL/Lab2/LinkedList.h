 /**
*	@file		LinkedList.h
*	@author		Austin Bailey
*	@date		9/9/2015
*	@purpose	Header File for linked list class
*/ 
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes a LinkedList instance
		*  @return Initialzed LinkedList with m_size set to 0 and m_front set to nullptr
		*/
		LinkedList();

		/**
		*  @pre Instance of LinkedList
		*  @post all member variables are destroyed as well as every node in the list
		*  @return N/A
		*/
		~LinkedList();

		/**
		*  @pre Instance of LinkedList
		*  @post const
		*  @return true if the LinkedList is empty, false else
		*/
		bool isEmpty() const;

		/**
		*  @pre Instance of LinkedList
		*  @post const
		*  @return value of m_size
		*/
		int size() const;

		/**
		*  @pre Instance of LinkedList
		*  @post const
		*  @return true if value is found in the LinkedList, false else
		*/
		bool search(int value) const;

		/**
		*  @pre Instance of LinkedList
		*  @post const (prints out list)
		*  @return void
		*/
		void printList() const;

		/**
		*  @pre Instance of LinkedList
		*  @post Node with m_value=value added to back of list
		*  @return void
		*/
		void addBack(int value);
		
		/**
		*  @pre Instance of LinkedList
		*  @post Node with m_value = value added to front of list
		*  @return Initialzed Node with m_value set to 0 and m_next set to nullptr
		*/
		void addFront(int value);

		/**
		*  @pre Instance of LinkedList
		*  @post removes a node from the back of the list
		*  @return true if removal is successful false else (empty List)
		*/
		bool removeBack();

		/**
		*  @pre Instance of LinkedList
		*  @post Removes a Node from the front of the list
		*  @return true if removal is successful, false if the list is empty
		*/
		bool removeFront();

	private:
		Node* m_front;	//points to the front node of the linkedlist
		int m_size;	//number of nodes in the list
};
#endif
