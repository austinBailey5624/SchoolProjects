/**
*	@file:		Stack.h
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	Header file for stack class
*/  
#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "PreconditionViolationException.h"
#include "Node.h"
template <typename T>
class Stack:public StackInterface<T>
{
	public:
		/**
		*  @pre None
		*  @post creates an instance of the stack class
		*  @return an instance of the stack class
		*/
		Stack();

		/**
		*  @pre An instance of the stack class
		*  @post destructor
		*  @return destructor
		*/
		~Stack();

		/**
		*  @pre instance of stack class
		*  @post const
		*  @return true if empty false else
		*/
		bool isEmpty() const;

		/**
		*  @pre instance of stack class
		*  @post a new node on top of stack
		*  @return void
		*/
		void push(const T newEntry);

		/**
		*  @pre instance of stack class
		*  @post stack looses top node
		*  @return void
		*  @throw PreconditionViolationException if stack is empty
		*/
		void pop()throw(PreconditionViolationException);

		/**
		*  @pre instance of stack class
		*  @post const
		*  @return value of top node if stack is not empty
		*  @throw PreconditionviolationException if stack is empty
		*/
		T peek()const throw(PreconditionViolationException);
		
		/**
		*  @pre instance of stack class
		*  @post const
		*  @return m_size
		*/
		int size() const;

		/**
		*  @pre instance of stack class
		*  @post const //but inside method prints out stack
		*  @return void
		*/
		void print() const;
	
	private:
		int m_size;
		Node<T>* m_top;
};
#include "Stack.hpp"
#endif
