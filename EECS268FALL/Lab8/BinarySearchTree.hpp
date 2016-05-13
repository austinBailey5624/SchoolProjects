/**
*	@file:		BinarySearchTree.hpp
*	@author:	Austin Bailey
*	@date:		4/10/2015
*	@purpose:	implementation file for the templated BinarySearchTree class
**/ 
#include "Node.h"
#include <vector>
template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root=nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	m_root=nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(m_root);
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

	return add(value,m_root);
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
bool BinarySearchTree<T>::search(T value) const throw(ValueNotFoundException)
{
	if(isEmpty())
	{
		std::cout << "Value is not on the list.";
		return false;
	}
	else if(value<this->m_root->getValue())
	{
		return search2(value, m_root->getLeft());
	}
	else if(value>this->m_root->getValue())
	{
		return search2(value, m_root->getRight());
	}
	return false;
}

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
	if(subtree==nullptr)
	{
		subtree=new Node<T>;
		subtree->setValue(value);
		return true;
	}
	else if(value<subtree->getValue())
	{
		if(subtree->getLeft()!=nullptr)
		{
			add(value,subtree->getLeft());
		}
		else
		{
			Node<T>* temp=new Node<T>;
			subtree->setLeft(temp);
			subtree->getLeft()->setValue(value);	
		}
		return true;
	}
	else if(value>subtree->getValue())
	{
		if(subtree->getRight()!=nullptr)
		{
			add(value,subtree->getRight());
		}
		else
		{
			Node<T>* temp=new Node<T>;
			subtree->setRight(temp);
			subtree->getRight()->setValue(value);
		}
		return true;
	}
	
return false;//in the case of adding a value already in the tree
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
{
	if(subtree->Node<T>::getLeft()!=nullptr)
	{
		deleteTree(subtree->Node<T>::getLeft());
	}
	if(subtree->Node<T>::getRight()!=nullptr)
	{
		deleteTree(subtree->Node<T>::getRight());
	}
	delete subtree;
}

template <typename T>
bool BinarySearchTree<T>::search2(T value, Node<T>* subtree)const throw(ValueNotFoundException)
{
	if(subtree==nullptr)
	{
		throw(ValueNotFoundException("number does not exist in main"));
	}
	if(value<subtree->getValue())
	{
		return search2(value,subtree->getLeft());
	}
	else if(value>subtree->getValue())
	{
		return search2(value,subtree->getRight());
	}
	else if(value==subtree->getValue())
	{
		return(true);
	}
	return false;
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

template <typename T>
std::vector<T> BinarySearchTree<T>::treeToVector(Order order)const
{
	std::vector<T> vec;
	tree2Vec(order, m_root, vec);
	return vec;
}

template <typename T>
void BinarySearchTree<T>::tree2Vec(Order order, Node<T>* subtree, std::vector<T>& vec)const
{
	if(subtree==nullptr)
	{
		return;
	}
	if(order==PRE_ORDER)
	{
		vec.push_back(subtree->getValue());
		tree2Vec(order,subtree->getLeft(),vec);
		tree2Vec(order,subtree->getRight(),vec);
	}			
	else if(order==IN_ORDER)
	{
		tree2Vec(order,subtree->getLeft(),vec);
		vec.push_back(subtree->getValue());
		tree2Vec(order,subtree->getRight(),vec);
	}
	else if(order==POST_ORDER)
	{
		tree2Vec(order,subtree->getLeft(),vec);
		tree2Vec(order,subtree->getRight(),vec);
		vec.push_back(subtree->getValue());
	}
}

