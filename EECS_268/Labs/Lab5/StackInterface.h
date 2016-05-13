/**
*	@file: 		Stack.h
*	@author:	Austin Bailey
*	@date:		2.27.2015
*	@purpose:	Header file for the virtual StackInterface class
*/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H 
#include "PreconditionViolationException.h"
template <typename T>
class StackInterface
{	public:

		/**
		* @pre: A Stack inteface that needs to be destroyed 
		* @post: an empty space where the Stack Interface was
		* @return:nothing
		*/
		virtual ~StackInterface(){};

		/**
		* @pre: A stack interface 
		* @post: const
		* @return:true if stackinterface is empty false else
		*/
		virtual bool isEmpty() const =0;

		/**
		* @pre: An instance of a stack interface
		* @post: a new top node with value newEntry
		* @return:void
		*/
		virtual void push(const T newEntry)=0;

		/**
		* @pre: An instance of a stack interface 
		* @post: a smaller stack inteface, with the old top missing
		* @return: the value of the deleted node
		* @throws: an exception if the stack is empty
		*/
		virtual T pop() throw(PVE)=0;

		/**
		* @pre: An instance of a stack interface
		* @post: const
		* @return: the value of the top node on the stack
		* @throws: an exception if the stack is empty
		*/
		virtual T peek() const throw(PVE)=0;

		/**
		* @pre: An instance of a stack interface 
		* @post: const
		* @return: the size of the stack
		*/
		virtual int size() const=0;

		/**
		* @pre: An instance of a stack interface 
		* @post: const (prints the stack
		* @return: void
		*/
		virtual void print() const =0;

		/**
		* @pre: Two stack interfaces
		* @post: const
		* @return: true if lhs(size) is < rhs(size)
		*/
		virtual bool operator< (const StackInterface<T>& rhs) const = 0;

		/**
		* @pre: Two stack interfaces
		* @post: const
		* @return: true if lhs(size) is <= rhs(size)
		*/
		virtual bool operator<=(const StackInterface<T>& rhs) const = 0;

		/**
		* @pre: Two stack interfaces
		* @post: const
		* @return: true if lhs(size) is > rhs(size)
		*/
		virtual bool operator> (const StackInterface<T>& rhs) const = 0;

		/**
		* @pre: Two stack interfaces
		* @post: const
		* @return: true if lhs(size) is >= rhs(size)
		*/
		virtual bool operator>=(const StackInterface<T>& rhs) const = 0;

		/**
		* @pre: Two stack interfaces
		* @post: const
		* @return: true if lhs(size) is == rhs(size)
		*/
		virtual bool operator==(const StackInterface<T>& rhs) const = 0;

		/**
		* @pre: Two stack interfaces
		* @post: const
		* @return: true if lhs(size) is != rhs(size)
		*/
		virtual bool operator!=(const StackInterface<T>& rhs) const = 0;

		/**
		* @pre: A stack interface
		* @post: const
		* @return: a pointer to the top
		*/
		virtual Node<T>* getTop()const=0;

};
#endif
