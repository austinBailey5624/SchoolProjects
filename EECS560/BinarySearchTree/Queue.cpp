/**
 *    @file:            queue.cpp
 *    @author:          Austin Bailey
 *    @date:           9.23.2016
 *    @purpose:         needed for the implementation of the levelorder print
*/
#include "Queue.h"

Queue::Queue()
{
      m_first=nullptr;
}

Queue::~Queue()
{
      while(m_first!=nullptr)
      {
            dequeue();
      }
}
bool Queue::isEmpty()
{
//      std::cout << "is this the issue?";
      return (m_first==nullptr);
}
void Queue::enqueue(Node* last)
{
      if(m_first==nullptr)//if queue is empty add to front
      {
//            std::cout << "empty enque reached\n";
            m_first=last;
//            std::cout << "We enqueued " << last->getValue() << "\n";
            return;
      }
      Node* temp = m_first;
      while(temp->getNext()!=nullptr)//makes temp look at the last Node
      {
            // if(temp->getNext()==temp)
            // {
            //       std::cout << "ERROR! Temp->getNext==temp\n";
            //       std::cout << "temp= " << temp->getValue() << "\n";
            //       std::cout << "temp->getnext =" << temp->getNext()->getValue() << "\n";
            //       return;
            // }
            // if(temp->getNext()->getNext()==temp)
            // {
            //       std::cout << "ERROR!!! Temp->getNext->getNext==temp\n";
            //       std::cout << "temp= " <<temp->getValue() << "\n";
            //       std::cout << "temp.next= " <<temp->getNext()->getValue() << "\n";
            //       std::cout << "temp.next.next= " << temp->getNext()->getNext()->getValue() << "\n";
            //       return;
            // }
//            std::cout << "temp= " << temp->getValue() << "\n";
//            std::cout << "temp->getnext = " << temp->getNext()->getValue() << "\n";
            temp=temp->getNext();
      }
      temp->setNext(last);
//      std::cout << "We enqueued  " << last->getValue() << "\n";
      return;
}

Node* Queue::dequeue()
{
      if(m_first==nullptr)//handles empty case
      {
//            std::cout << "Attempted empty dequeue\n";
            return nullptr;
      }
      else if(m_first->getNext()==nullptr)//handles size=1 case
      {
//            std::cout <<"Attempted size=1 dequeue\n";
            Node* temp = m_first;
//            delete m_first;//TODO fix possible error?
            m_first=nullptr;
//            std::cout << "we dequeued " << temp->getValue() << "\n";
            return temp;
      }
//      std::cout << "m_first begins as = " << m_first->getValue() << "\n";
//      std::cout << "Attempted general dequeue\n";
      Node* temp = m_first;
//      delete m_first;
      m_first = m_first->getNext();
//      std::cout << "m_first becomes: " << m_first->getValue() << "\n";
//      std::cout << "we dequeued " << temp->getValue() << "\n";
      return temp;
}

Node* Queue::getFirst()const
{
      return m_first;
}
