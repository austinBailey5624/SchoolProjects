/**
*	@file:		Node.h
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	Header file for the Node class
*/
#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes a Node instance
		*  @return Initialzed Node instace with value set to default constructor and m_next set to nullptr
		*/
		Node();

		/**
		*  @pre instance of node class
		*  @post sets m_value to value
		*  @return void
		*/
		void setValue(T value);

		/**
		*  @pre Instance of Node class
		*  @post const
		*  @return m_value
		*/	
		T getValue()const;

		/**
		*  @pre Instance of Node class
		*  @post sets m_next to next
		*  @return void
		*/
		void setNext(Node<T>* next);

		/**
		*  @pre Instance of Node class
		*  @post const
		*  @return m_next
		*/
		Node<T>* getNext()const;
		
	private:
		T m_value;
		Node<T>* m_next;
};
#include "Node.hpp"
#endif  
