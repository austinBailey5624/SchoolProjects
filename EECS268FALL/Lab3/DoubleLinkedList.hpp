/**
*	@file		DoubleLinkedList.hpp
*	@author		Austin Bailey
*	@date		9/21/2015
*	@purpose	implementation file for the doublelinkedlist class
*/
 
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_size=0;
	m_front=nullptr;
	m_back=nullptr;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while(m_front!=nullptr)
	{
		this->removeFront();
	}
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()const
{
	return m_front=nullptr;
}

template <typename T>
int DoubleLinkedList<T>::size()const
{
	return m_size;
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	Node<T>* temp = new Node<T>(value);
	Node<T>* temp2 = m_front;
	if(m_front==nullptr)			//case empty
	{
		m_front=temp;
		m_back=temp;
		temp->setPrevious(nullptr);
		temp->setNext(nullptr);
	}
	else 
	{
		temp2=m_front;
		m_front=temp;
		temp->setPrevious(nullptr);
		temp->setNext(temp2);
		temp2->setPrevious(temp);
	}
	m_size++;
}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	Node<T>* temp = new Node<T>(value);
	Node<T>* temp2 = m_back;
	if(m_front==nullptr)
	{
		m_front=temp;
		m_back=temp;
		temp->setPrevious(nullptr);
		temp->setNext(nullptr);
	}
	else
	{
//		temp2=m_back;		//redundant?
		m_back=temp;
		temp->setNext(nullptr);
		temp->setPrevious(temp2);
		temp2->setNext(temp);
	}
	m_size++;
}

template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
	if(m_front==nullptr)			//handles empty case
	{		
		return false;
	}
	else if(m_front==m_back)
	{
		delete m_back;
		m_front=nullptr;
		m_back=nullptr;
	}
	Node<T>* temp = m_back->getPrevious();	//handles nonempty case
	delete m_back;
	m_back=temp;
	temp->setNext(m_back);
	m_size--;
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
	if(m_front==nullptr)			//handles empty case
	{
		return false;
	}
	else if(m_front==m_back)
	{
		delete m_front;
		m_front=nullptr;
		m_back=nullptr;
	}
	else
	{
		Node<T>* temp = m_front->getNext();	//handles nonempty case
		delete m_front;
		m_front=temp;
		temp->setPrevious(m_front);
		m_size--;
	}
	return true;
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
	if(m_front==nullptr)
	{
		return false;
	}
	Node<T>* temp=find(value);
	if(temp==nullptr)
	{
		std::cout << "Value not in list";
		return false;
	}
	else if(temp==m_front)
	{
		removeFront();
	}
	else if(temp==m_back)
	{
		removeBack();
	}
	else
	{
		temp->getPrevious()->setNext(temp->getNext());
		temp->getNext()->setPrevious(temp->getPrevious());
		delete temp;
		m_size--;
	}
	return true;
}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue)throw(std::runtime_error)
{
	Node<T>* temp =find(listValue);
	if(temp==nullptr)
	{
		throw(std::runtime_error("Value not in list"));
		return;
	}
	if(m_back==temp)			//handles case where node is at back of list
	{
		this->pushBack(newValue);
	}
	else//seg fault here
	{
		Node<T>* temp2 = new Node<T>(newValue);
		temp2->setNext(temp->getNext());
		temp2->setPrevious(temp);
		temp->setNext(temp2);
		temp2->getNext()->setPrevious(temp2);
		m_size++;
	}
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue)throw(std::runtime_error)
{
	Node<T>* temp=find(listValue);
	if(temp==nullptr)
	{
		throw(std::runtime_error("Value not in list"));
		return;
	}
	if(m_front==temp)
	{
		pushFront(newValue);
	}
	else
	{
		Node<T>* temp2=new Node<T>(newValue);
		temp2->setNext(temp);
		temp2->setPrevious(temp->getPrevious());
		temp->setPrevious(temp2);
		temp2->getPrevious()->setNext(temp2);
		m_size++;
	}
}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value)const
{
	Node<T>* temp =m_front;
	while(temp!=nullptr)
	{
		if(temp->getValue()==value)
		{
			return temp;
		}
		temp=temp->getNext();
	}
	return nullptr;
}

template <typename T>
void DoubleLinkedList<T>::printList()const
{
	if(m_front==nullptr)
	{
		std::cout << "";
		return;
	}
	Node<T>* temp=m_front;
	while(temp!=m_back)
	{
		std::cout << temp->getValue() << " ";
		temp=temp->getNext();
	}
	if(temp==m_back)
	{
		std::cout << m_back->getValue() << " \n";
	}
}

template <typename T>
Node<T>* DoubleLinkedList<T>::getFront()const
{
	return m_front;
}

template <typename T>
void DoubleLinkedList<T>::setFront(Node<T>* front)
{
	m_front=front;
}


template <typename T>
Node<T>* DoubleLinkedList<T>::getBack()const
{
	return m_back;
}

template <typename T>
void DoubleLinkedList<T>::setBack(Node<T>* back)
{
	m_back = back;
}
