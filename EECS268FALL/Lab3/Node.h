/**
*	@file		Node.h
*	@author		Austin Bailey
*	@date		9/21/2015
*	@purpose	Header file for Node class
*/

#ifndef NODE_H
#define NODE_H
template <typename T>
class Node
{
	public:
		Node();
		Node(T value);
		T getValue()const;
		void setValue(T value);
		Node<T>* getPrevious()const;
		void setPrevious(Node<T>* previous);
		Node<T>* getNext()const;
		void setNext(Node<T>* next);
		
	private:
		T m_value;
		Node<T>* m_previous;
		Node<T>* m_next;
};
#include "Node.hpp"
#endif 
