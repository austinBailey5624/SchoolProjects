/**
*	@file:		Node.h
*	@author:	Austin Bailey
*	@date:		4/10/2015
*	@purpose:	Header file for the templated Node class
**/  
#ifndef NODE_H
#define NODE_H
template<typename T>
class Node
{
	public:
		Node();
		Node(const Node<T>& other);
		T getValue();
		Node<T>* getLeft();
		Node<T>* getRight();
		void setValue(T value);
		void setLeft(Node<T>* left);
		void setRight(Node<T>* right);
	private:
		Node<T>* m_left;
		Node<T>* m_right;
		T m_value;
};
#include "Node.hpp"
#endif
