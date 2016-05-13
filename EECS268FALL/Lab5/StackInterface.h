/**
*	@file:		StackInterface.h
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	header file for the interface StackInterface
*/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include <stdexcept>
#include "PreconditionViolationException.h"
template <typename T>
class StackInterface
{
	public:
		/**
		*  @pre Instance of StackInterface
		*  @post destructor
		*  @return destructor
		*/
		virtual ~StackInterface(){};

		/**
		*  @pre Instance of StackInterface or Inheritors
		*  @post const
		*  @return true if empty false else
		*/
		virtual bool isEmpty() const =0;

		/**
		*  @pre Instance of StackInterfaces progeny
		*  @post new node on top
		*  @return void
		*/
		virtual void push(const T newEntry)=0;

		/**
		*  @pre Instance of StackInterface or Inheritors
		*  @post deletes top node
		*  @return void
		*  @throw PreconditionViolationException if empty
		*/
		virtual void pop()throw(PreconditionViolationException)=0;

		/**
		*  @pre Instance of StackInterface or Inheritors
		*  @post const
		*  @return m_value of top node
		*  @throw PreconditionViolationException if empty
		*/
		virtual T peek() const throw(PreconditionViolationException)=0;

		/**
		*  @pre Instance of StackInterface or Inheritors
		*  @post const
		*  @return m_size
		*/
		virtual int size()const=0;

		/**
		*  @pre Instance of stackInterface or Inheritors
		*  @post const
		*  @return void
		*/
		virtual void print() const=0;
};   
#endif
