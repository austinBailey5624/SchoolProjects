/**
*	@file:		Node.hpp
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	implementation file for the templated node class
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
T Node<T>::getValue()const
{
	return m_value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next=next;
}

template <typename T>
Node<T>* Node<T>::getNext()const
{
	return m_next;
}
