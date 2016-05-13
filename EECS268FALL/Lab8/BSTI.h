#ifndef BSTI_H
#define BSTI_H
#include "ValueNotFoundException.h"
#include "Node.h"
#include <stdexcept>
#include <vector>
enum Order
{
	PRE_ORDER,IN_ORDER,POST_ORDER
};
template <typename T>
class BSTI 
{
	public:
		/**
		*	@pre:	none
		*	@post:	creates a BSTI
		*	@return:a BSTI	
		**/
		virtual ~BSTI(){}

		/*
		*	@pre:	instance of BSTI or is inheritors	
		*	@post:	pointer to copy of BSTI's inheritor
		*	@return:Pointer ot copy of BSTI's inheritor
		*/
		virtual BSTI<T>* clone() = 0;
		
		/*
		*	@pre:	instance of BSTI inheritor	
		*	@post:	const
		*	@return:true if empty false else
		*/
		virtual bool isEmpty() const = 0;

		/*
		*	@pre:	instance of BSTI inheritor	
		*	@post:	adds a node of m_value value to the tree
		*	@return:true if add successful false else
		*/
		virtual bool add(T value) = 0;

		/*
		*	@pre:	Instance of a BSTI inheritor
		*	@post:	searches for a value
		*	@return:true if found false else
		*/
		virtual bool search(T value)const throw(ValueNotFoundException)=0;

		/*
		*	@pre:	Instance of a BSTI inheritor
		*	@post:	searches for a value
		*	@return:true if found false else
		*/
		virtual bool search2(T value, Node<T>*) const throw(ValueNotFoundException) = 0;

		/*
		*	@pre:	Instance of a BSTI inheritor
		*	@post:	helper method for above search
		*	@return:
		*/
		virtual void printTree(Order order) const = 0;

		/*
		*	@pre:	Instance of a BSTI inheritor
		*	@post:	const-but prints inorder
		*	@return:void
		*/
		virtual void sortedPrint() const = 0;

		/*
		*	@pre:	instance of BSTI inheritor
		*	@post:	const
		*	@return:returns vector containing tree in the provided order
		*/
		virtual std::vector<T> treeToVector(Order order)const=0;
};
#endif 
