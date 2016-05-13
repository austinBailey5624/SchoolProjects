#ifndef BSTI_H
#define BSTI_H
#include "ValueNotFoundException.h"
#include "Node.h"
#include <stdexcept>
enum Order
{
	PRE_ORDER,IN_ORDER,POST_ORDER
};
template <typename T>
class BSTI 
{
	public:
		/**
		*	@pre:	the desire to not create a virtual class that needs a constructor anyway
		*	@post:	creates a BSTI
		*	@return:a BSTI	
		**/
		virtual ~BSTI(){}
		virtual BSTI<T>* clone() = 0;
		virtual bool isEmpty() const = 0;
		virtual bool add(T value) = 0;
		virtual T search(T value)const throw(ValueNotFoundException)=0;
		virtual T search(T value, Node<T>*) const throw(ValueNotFoundException) = 0;
		virtual void printTree(Order order) const = 0;
		virtual void sortedPrint() const = 0;
};//bst1.printTree(Order:IN_ORDER);
#endif 
