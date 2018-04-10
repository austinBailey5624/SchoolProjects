/**
*     @file:      Node.h
*     @author:    Austin Bailey
*     @date:      9/20/2016
*/

#ifndef NODE_H
#define NODE_H

class Node
{
      public:
            Node();
            Node(int value);
            ~Node();
            int getValue()const;
            void setValue(int value);
            Node* getLeft()const;
            void setLeft(Node* left);
            Node* getRight()const;
            void setRight(Node* right);
            Node* getNext()const;
            void setNext(Node* next);
      private:
            Node* m_left;
            Node* m_right;
            Node* m_next;//for use by queue
            int m_value;

};
#endif
