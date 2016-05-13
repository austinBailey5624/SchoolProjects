/**
*	@file:		Stack.hpp
*	@author:	Austin Bailey
*	@date:		9/28/2015
*	@purpose:	implementation file for the stack class
*/  
template <typename T>
Stack<T>::Stack()
{
	this->m_size=0;
	this->m_top=nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	while(m_top!=nullptr)
	{
		pop();
	}
}

template <typename T>
bool Stack<T>::isEmpty()const
{
	return m_top==nullptr;
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
	Node<T>* temp=new Node<T>;
	temp->setValue(newEntry);
	if(isEmpty())
	{
		m_top=temp;
		temp->setNext(nullptr);
		m_size++;
		return;
	}
	temp->setNext(m_top);
	m_top=temp;
	m_size++;
}

template <typename T>
void Stack<T>::pop()throw(PreconditionViolationException)
{
	if(isEmpty())
	{
		throw PreconditionViolationException("Stack empty");
	}
	Node<T>* temp=m_top;
	m_top=temp->getNext();
	delete temp;
	temp=nullptr;
	m_size--;
}

template <typename T>
T Stack<T>::peek()const throw(PreconditionViolationException)
{
	if(isEmpty())
	{
		throw PreconditionViolationException("Stack is empty, cannot peek");
	}
	return(m_top->getValue());
}

template <typename T>
int Stack<T>::size()const
{
	return m_size;
}

template <typename T>
void Stack<T>::print() const
{
	Node<T>* temp=m_top;
	while(temp!=nullptr)
	{
		std::cout<< temp->getValue() << " ";
		temp=temp->getNext();
	}
}
