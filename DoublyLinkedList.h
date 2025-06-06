//Name: Imad Farhat
#pragma once
#include <iostream>
#include "DoublyLinkedListNode.h"

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	//constructor and destructor
	void push_front(short value);
	void pop_front();
	void insert(int positionIndex, short value);
	bool empty();
	int size();
	void erase(int positionIndex);
	int find(short value);
	//library functions from doublylinkedlist library

	friend std::ostream& operator <<(std::ostream& ostr, const DoublyLinkedList& rhs);
	short operator[](int index);
	//operator overloads to print and to get value at an index

private:
	DoublyLinkedListNode* head;
	//stores head as private node
};