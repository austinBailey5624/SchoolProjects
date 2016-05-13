/**
*	@file		DoubleLinkedList.h/
*	@author		Austin Bailey
*	@date		9/21/2015
*	@purpose	Header file of the DoubleLinkedList class
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
#include <iostream> 
#include <string>
#include <stdexcept>

template <typename T>
class DoubleLinkedList
{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes a DoubleLinkedList instance
		*  @return Initialzed a DoubleLinkedList m_front and m_back set to nullptr and m_size set to 0
		*/
		DoubleLinkedList();

		/**
		*  @pre Instance of the DoubleLinkedList class
		*  @post Deletes every node in the list and then the list itself
		*  @return Destructor
		*/
		~DoubleLinkedList();

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post const
		*  @return True if empty, false else
		*/
		bool isEmpty() const;

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post const
		*  @return value of m_size
		*/
		int size() const;

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post pushes a node of m_value value to the front of the list
		*  @return void
		*/
		void pushFront(T value);

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post instance of DoubleLinkedList class with a node of m_value value at the back of the list
		*  @return void
		*/
		void pushBack(T value);

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post removes a node from the back of the list
		*  @return true if remove was successful false else
		*/
		bool removeBack();

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post removes a node from the back of the list
		*  @return true if remove was successful false else
		*/
		bool removeFront();

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post removes the first node of m_value value from the list
		*  @return true if remove was successful false else
		*/
		bool remove(T value);

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post inserts a new node of value newValue ahead of the first node in the list of value listValue
		*  @throws std::runtime error if the listValue is not in the list 
		*  @return void
		*/
		void insertAhead(T listValue, T newValue)throw(std::runtime_error);

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post inserts a new node of value newValue behind of the first node in the list of value listValue
		*  @return void
		*  @throws std::runtime error if the listValue is not in the list 
		*/
		void insertBehind(T listValue, T newValue)throw(std::runtime_error);

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post const
		*  @return a pointer to the first node of m_value value
		*/
		Node<T>* find(T value)const;

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post const, prints the list
		*  @return void
		*/
		void printList() const;

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post const
		*  @return m_front
		*/
		Node<T>* getFront()const;

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post value of m_front is set to parameter front
		*  @return void
		*/
		void setFront(Node<T>* front);

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post const
		*  @return m_back
		*/
		Node<T>* getBack()const;

		/**
		*  @pre Instance of DoubleLinkedList class
		*  @post sets the value of m_back to parameter front
		*  @return void
		*/
		void setBack(Node<T>* back);
	private:
		Node<T>* m_front;
		Node<T>* m_back;
		int m_size;
};
#include "DoubleLinkedList.hpp"
#endif
