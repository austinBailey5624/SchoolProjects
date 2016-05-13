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
		/*
		*	@pre:	none
		*	@post:	constructor
		*	@return:constructor
		*/
		Node();

		/*
		*	@pre:	none
		*	@post:	constructor
		*	@return:constructor
		*/
		Node(const Node<T>& other);

		/*
		*	@pre:	instance of Node
		*	@post:	const
		*	@return:m_value
		*/
		T getValue()const;

		/*
		*	@pre:	instance of Node
		*	@post:	const
		*	@return:m_Left
		*/
		Node<T>* getLeft()const;

		/*
		*	@pre:	instance of Node	
		*	@post:	const
		*	@return:m_right
		*/
		Node<T>* getRight()const;

		/*
		*	@pre:	instance of Node	
		*	@post:	sets m_value to value
		*	@return:void
		*/
		void setValue(T value);

		/*
		*	@pre:	instance of Node	
		*	@post:	sets m_left to left
		*	@return:void
		*/
		void setLeft(Node<T>* left);

		/*
		*	@pre:	instance of Node
		*	@post:	sets m_right to right
		*	@return:void
		*/
		void setRight(Node<T>* right);
	private:
		Node<T>* m_left;
		Node<T>* m_right;
		T m_value;
};
#include "Node.hpp"
#endif
