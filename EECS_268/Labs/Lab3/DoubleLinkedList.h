/**
*	@file: 		DoubleLinkedList.h
*	@author:	Austin Bailey
*	@date:		2.13.2015
*	@purpose:	header file for DoubleLinkedList class
*/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
template <typename T>
class DoubleLinkedList
{
	public:
		/**
		* @pre: the desire to create a doubly linked list
		* @post:the creation of a doubly linked list
		* @return: Your brand new doubly linked list
		*/
		DoubleLinkedList();

		/**
		* @pre: a doubly linked list you don't like anymore...
		* @post: All values within die
		* @return: the death of your beloved doubly linked list
		*/
		~DoubleLinkedList();
		
		/**
		* @pre: an instance of the doubleLinkedList
		* @post: Values don't change (const)
		* @return: true if its empty, false else
		*/
		bool isEmpty()const;
	
		/**
		* @pre: an instance of the doubly linked list
		* @post: Values don't change, (const)
		* @return: the death of your beloved doubly linked list
		*/
		int size() const;

		/**
		* @pre: an instance of the double linked list
		* @post: a new node on the front of the double linked list with given value
		* @return: void
		*/
		void pushFront(T value);

		/**
		* @pre: an instance of the double linked list
		* @post: a new node on the back of the double linked list with given value
		* @return: void
		*/
		void pushBack(T value);

		/**
		* @pre: an instance of the double linked list
		* @post: remove a node of m_value T value
		* @return: true if node was removed false else
		*/
		bool remove(T value)throw(std::runtime_error);

		/**
		* @pre: an instance of the double linked list
		* @post: a new node in front of the first node with given value
		* @return: void
		*/
		void insertAhead(T listValue, T newValue)throw(std::runtime_error);

		/**
		* @pre: an instance of the double linked list
		* @post: a new node behind the first node with given value
		* @return: void
		*/
		void insertBehind(T listValue, T newValue)throw(std::runtime_error);


		/**
		* @pre: an instance of the double linked list
		* @post: const
		* @return: a pointer to the first node in the list
		*/
		Node<T>* find(T value) const;
		
		/**
		* @pre: an instance of the double linked list
		* @post: const, prints list to screen
		* @return: void
		*/
		void printList() const;
		
		
	private:
		Node<T>* m_back;
		Node<T>* m_front;
		int m_size;
}; 
#include "DoubleLinkedList.hpp"
#endif
