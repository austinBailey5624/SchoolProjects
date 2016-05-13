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
		/*
		*	@pre:	none	
		*	@post:	instance of BinarySearchTree
		*	@return:constructor
		*/
		BinarySearchTree();

		/*
		*	@pre:	none
		*	@post:	instance of BinarySearchTree
		*	@return:constructor
		*/
		BinarySearchTree(const BinarySearchTree<T>& other);

		/*
		*	@pre:	instance of BinarySearchTree
		*	@post:	destructor
		*	@return:destructor
		*/
		~BinarySearchTree();

		/*
		*	@pre:	instance of BinarySearchTree	
		*	@post:	creates a copy of tree
		*	@return:pointer to the copy of the tree
		*/
		BSTI<T>* clone();

		/*
		*	@pre:   instance of BinarySearchTree	
		*	@post:	const
		*	@return:returns true if empty false else
		*/
		bool isEmpty()const;

		/*
		*	@pre:	instance of BinarySearchTree
		*	@post:	a new node on the BinarySearchTree with m_value value
		*	@return: true if successful, false else
		*/
		bool add(T value);

		/*
		*	@pre:	instance of BinarySearchTree
		*	@post:	const-but prints tree in order specified
		*	@return:void
		*/
		void printTree(Order order)const;

		/*
		*	@pre:	instance of Binary SearchTree
		*	@post:	const-but prints tree in order
		*	@return:void
		*/
		void sortedPrint() const;

		/*
		*	@pre:	instance of BinarySearchTree
		*	@post:	const
		*	@return:true if in tree, false else
		*	@throw:	if value not found
		*/
		bool search(T value) const throw(ValueNotFoundException);

		/*
		*	@pre:	instance of BinarySearchTree	
		*	@post:	const
		*	@return:std::vector containing tree in specified order
		*/
		std::vector<T> treeToVector(Order order)const;

		/*
		*	@pre:	instance of binarySearchtree
		*	@post:	prints the tree in to a vector by the given order
		*	@return:void
		*/
		void tree2Vec(Order order, Node<T>* subtree, std::vector<T>& vec)const;
	private:
		Node<T>* m_root;
		bool add(T value, Node<T>* subtree);
		void deleteTree(Node<T>* subtree);
		bool search2(T value, Node<T>* subtree) const throw(ValueNotFoundException);
		void printTree(Node<T>* subtree, Order order)const;
};
#include "BinarySearchTree.hpp"
#endif
