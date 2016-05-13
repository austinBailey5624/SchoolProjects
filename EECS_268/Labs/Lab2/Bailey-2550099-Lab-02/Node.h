/**
*	@file: 		Node.h
*	@author:	Austin Bailey
*	@date:		2.5.2015
*	@purpose:	Header File for Node Class
*/

#ifndef NODE_H
#define NODE_H
#include <cstdio>
class Node
{
	public:
	/**
	* @pre None
	* @post Creates and initalizes a Node instance
	* @return Initialized Node with m_value set to zero and m_next set to nullptr
	*/
	Node();

	/**
	* @pre instance of Node
	* @post sets m_value to value
	* @return returns void
	*/
	void setValue(int value);

	/**
	* @pre instance of Node
	* @post does not change instance
	* @return returns m_value
	*/
	int getValue()const;

	/**
	* @pre instance of Node
	* @post sets value of m_next to prev
	* @return returns void
	*/
	void setNext(Node* next);

	/**
	* @pre instance of Node
	* @post does not change instane
	* @return returns m_next
	*/	
	Node* getNext();
	private:
	int m_value;	//holds a value	
	Node* m_next; 	//points to next node

};
#endif
