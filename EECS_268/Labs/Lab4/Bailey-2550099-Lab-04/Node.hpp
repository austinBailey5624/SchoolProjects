/**
*	@file: 		Node.hpp
*	@author:	Austin Bailey
*	@date:		2.13.2015
*	@purpose:	implementation file for node class
*/
template <typename T>  
Node<T>::Node()
{
	m_next=nullptr;
	m_value=T();
}

template <typename T>
void Node<T>::setValue(T value)
{
	m_value=value;	
}

template <typename T>
T Node<T>::getValue() const
{
	return m_value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	this->m_next=next;
}

template <typename T>
Node<T>* Node<T>::getNext()const
{
	return m_next;
}

