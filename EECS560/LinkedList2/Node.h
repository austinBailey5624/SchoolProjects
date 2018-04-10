/**
*	@file:		Node.h
*	@author:	Austin Bailey
*	@date:		8.26.2016
*/
#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		Node();
		~Node();
		Node* getNext();
		int getValue();
		void setNext(Node* next);
		void setValue(int value);
	
	private:
		Node* m_next;
		int m_value;
		
};
#endif	
