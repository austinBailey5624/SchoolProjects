/**
*	@file:		Node.h
*	@author:	Austin Bailey
*	@date:		9/11/2015
*	@purpose:	Header File for the Node Class
**/

#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes a Node instance
		*  @return Initialzed Node with m_value set to 0 and m_next set to nullptr
		*/
		Node();
		
		/**
		*  @pre None
		*  @post Creates and initializes a Node instance with m_value set to value
		*  @return Initialized Node with m_value set to value and m_next set to nullptr
		*/
		Node(int value);

		/**
		*  @pre Instance of Node Class
		*  @post sets m_value to val
		*  @return void
		*/
		void setValue(int val);

		/**
		*  @pre Instance of Node Class
		*  @post member variables unchanged
		*  @return value of m_value
		*/
		int getValue() const;

		/**
		*  @pre Instance of Node Class
		*  @post sets m_next to prev
		*  @return void
		*/
		void setNext(Node* prev);

		/**
		*  @pre Instance of Node Class
		*  @post member variables unchanged
		*  @return value of m_next
		*/
		Node* getNext() const;
	
	private:
		int m_value;	//used to hold value
		Node* m_next;	//used to point to the next node on the LinkedList
}; 
#endif
