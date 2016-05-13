/**
*	@file:		BinarySearchTree.hpp
*	@author:	Austin Bailey
*	@date:		4/10/2015
*	@purpose:	implementation file for the templated BinarySearchTree class
**/ 
#include "Node.h"

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root=nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
//	deleteTree(this->m_root());
}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
	BSTI<T>* returnness = new BinarySearchTree<T>;
	return returnness;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	return (m_root==nullptr);
}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
	if(this->m_root==nullptr)
	{
		m_root->setValue(value);
	}
	return true;
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order)const
{
	if(isEmpty())
	{
		std::cout << "The list is empty";
	}
	else if(order==PRE_ORDER)
	{
		printTree(this->m_root, PRE_ORDER);
	}
	else if(order==IN_ORDER)
	{
		printTree(this->m_root, IN_ORDER);
	}
	else if(order==POST_ORDER)
	{
		printTree(this->m_root, POST_ORDER);
	}
}

template <typename T>
void BinarySearchTree<T>::sortedPrint()const
{
	if(isEmpty())
	{
		std::cout << "The list is empty";
		return;
	}
	printTree(this->m_root, IN_ORDER);
}
template <typename T>
T BinarySearchTree<T>::search(T value) const throw(ValueNotFoundException)
{
	if(isEmpty())
	{
		std::cout << "Value is not on the list.";
		return value;
	}
	else if(value<this->m_root->getValue())
	{
		return search(value, m_root->getLeft());
	}
	else if(value>this->m_root->getValue())
	{
		return search(value, m_root->getRight());
	}
}

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
return true;
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
	if(subtree->getLeft()!=nullptr)
	{
		deleteTree(subtree->getLeft);
	}
	if(subtree->getRight()!=nullptr)
	{
		deleteTree(subtree->getRight);
	}
	delete subtree;
}

template <typename T>
T BinarySearchTree<T>::search(T value, Node<T>* subtree)const throw(ValueNotFoundException)
{
	if(subtree==nullptr)
	{
//		throw(ValueNotFoundException("number does not exist in main"));
	}
	if(value<subtree->getValue())
	{
		return search(value,subtree->getLeft());
	}
	else if(value>subtree->getValue())
	{
		return search(value,subtree->getRight());
	}
	else if(value==subtree->getValue())
	{
		return(value);
	}
	return value;
}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order)const
{
	if(order==PRE_ORDER)
	{
		std::cout<< subtree->getValue();
		if(subtree->getLeft()!=nullptr)
		{
			printTree(subtree->getLeft(),PRE_ORDER);
		}
		if(subtree->getRight()!=nullptr)
		{
			printTree(subtree->getRight(),PRE_ORDER);
		}
	}
	else if(order==IN_ORDER)
	{
		if(subtree->getLeft()!=nullptr)
		{
			printTree(subtree->getLeft(),IN_ORDER);
		}
		std::cout << subtree->getValue();
		if(subtree->getRight()!=nullptr)
		{
			printTree(subtree->getRight(),IN_ORDER);
		}
	}
	else if(order==POST_ORDER)
	{
		if(subtree->getLeft()!=nullptr)
		{
			printTree(subtree->getLeft(),POST_ORDER);
		}
		if(subtree->getRight()!=nullptr)
		{
			printTree(subtree->getRight(),POST_ORDER);
		}
		std::cout << subtree->getValue();
	}

}
