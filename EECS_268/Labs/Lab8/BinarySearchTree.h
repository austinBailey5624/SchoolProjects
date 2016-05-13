/**
*	@file:		BinarySearchTree
*	@author:	Austin Bailey
*	@date:		4/10/2015
*	@purpose:	header file for the templated Node class
**/  
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdexcept>
#include "BSTI.h"
#include "Node.h"
#include "ValueNotFoundException.h"
template <typename T>
class BinarySearchTree: public BSTI<T>
{
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree<T>& other);
		~BinarySearchTree();
		BSTI<T>* clone();
		bool isEmpty()const;
		bool add(T value);
		void printTree(Order order)const;
		void sortedPrint() const;
		T search(T value) const throw(ValueNotFoundException);
	private:
		Node<T>* m_root;
		bool add(T value, Node<T>* subtree);
		void deleteTree(Node<T>* subtree);
		T search(T value, Node<T>* subtree) const throw(ValueNotFoundException);
		void printTree(Node<T>* subtree, Order order)const;
};
#include "BinarySearchTree.hpp"
#endif
