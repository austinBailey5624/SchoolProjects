/**
*	@file		Node.hpp
*	@author		Austin Bailey
*	@date		9/21/2015
*	@purpose	Implementation file for the Node class
*/

template <typename T>
Node<T>::Node()
{
	m_value=T();
	m_previous=nullptr;
	m_next=nullptr;
}

template <typename T>
Node<T>::Node(T value)
{
	m_value=value;
	m_previous=nullptr;
	m_next=nullptr;
}
template <typename T>
T Node<T>::getValue() const
{
	return m_value;
}

template <typename T>
void Node<T>::setValue(T value)
{
	m_value=value;
}

template <typename T> 
Node<T>* Node<T>::getPrevious()const
{
	return m_previous;
}

template <typename T>
void Node<T>::setPrevious(Node<T>* previous)
{
	m_previous=previous;
}

template <typename T>
Node<T>* Node<T>::getNext()const
{
	return m_next;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next=next;
}
