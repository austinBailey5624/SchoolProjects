/**
*	@file: 		Stack.hpp
*	@author:	Austin Bailey
*	@date:		2.27.2015
*	@purpose:	Implementation file for tempalated Stack class
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
	while(this->m_top!=nullptr)
	{
		this->pop();
	}
}

template <typename T>
bool Stack<T>::isEmpty()const
{
	return(m_size==0);
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
	Node<T>* tempNode = new Node<T>();
	tempNode->setValue(newEntry);
	tempNode->setNext(this->m_top);
	this->m_top=tempNode;
	this->m_size++;
}

template <typename T>
T Stack<T>::pop()throw(PVE)
{
	if(m_top==nullptr)
	{
		throw(PVE("Tried to Pop an empty stack"));
	}
	else
	{
		Node<T>* tempNode = this->m_top->getNext();
		T tempt = this->m_top->getValue();
		delete this->m_top;
		this->m_top=tempNode;
		this->m_size--;
		return tempt;		
	}
}

template <typename T>
T Stack<T>:: peek()const throw(PVE)
{
	if(m_top==nullptr)
	{
		throw(PVE("Tried to Peek at an empty stack"));
	}
	else
	{
		return this->m_top->getValue();
	}
}

template <typename T>
int Stack<T>::size()const
{
	return this->m_size;
}

template <typename T>
void Stack<T>::print() const
{
	Node<T>* tempNode=this->m_top;
	while(tempNode!=nullptr)
	{
		std::cout << tempNode->getValue();
		tempNode=tempNode->getNext();
	}
	std::cout<<"\n";
}
template <typename T>
bool Stack<T>::operator<(const StackInterface<T>& rhs)const
{
	return this->m_size<rhs.size();
}

template <typename T>
bool Stack<T>::operator<=(const StackInterface<T>& rhs)const
{
	return this->m_size<=rhs.size();
}

template <typename T>
bool Stack<T>::operator>(const StackInterface<T>& rhs)const
{
	return this->m_size>rhs.size();
}

template <typename T>
bool Stack<T>::operator>=(const StackInterface<T>& rhs)const
{
	return this->m_size>=rhs.size();
}

template <typename T>
bool Stack<T>::operator==(const StackInterface<T>& rhs)const
{
	return this->m_size==rhs.size();
}

template <typename T>
bool Stack<T>::operator!=(const StackInterface<T>& rhs)const
{
	return this->m_size!=rhs.size();
}

template <typename T>
Node<T>* Stack<T>::getTop()const
{
	return this->m_top;
}
