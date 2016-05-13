/**
*	@file:		Node.hpp
*	@author:	Austin Bailey
*	@date:		4/10/2015
*	@purpose:	implementation file for the templated Node class
**/ 
template <typename T>
Node<T>::Node()
{
	m_left=nullptr;
	m_right=nullptr;
	m_value=T();
}

template <typename T>
Node<T>::Node(const Node<T>& other)
{
	this->m_value = other.m_value;
	this->m_left = nullptr;
	this->m_right = nullptr;
	if(other.m_left!=nullptr)//if theres something there
	{
		this->m_left=new Node(*(other.m_left));
	}
	if(other.m_right!=nullptr)
	{
		this->m_left = new Node(*(other.m_right));
	}
}

template <typename T>
T Node<T>::getValue()const
{
	return m_value;
}

template <typename T>
Node<T>* Node<T>::getLeft()const
{
	return m_left;
}

template <typename T>
Node<T>* Node<T>::getRight()const
{
	return m_right;
}

template <typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left)
{
	this->m_left=left;
}

template <typename T>
void Node<T>::setRight(Node<T>* right)
{
	this->m_right = right;
}
