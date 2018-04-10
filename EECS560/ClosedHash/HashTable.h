/**
*	@file:		Hashtable.h
*	@author:	Austin Bailey
*	@date:		9.15.2016
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
	public:
		HashTable();
		~HashTable();
		bool insert(int value);
		bool remove(int value);//this is the function called when delete is selected from main
		void print();
		bool hash(int value, int i);//hash needs to know where we are in the for loop
		bool contains(int value);
		bool isFull();

	private:
		bool* m_flagField;
		int* m_hashField;
		int m_size;
			
		
};
#endif
