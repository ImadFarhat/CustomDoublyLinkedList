//Name: Imad Farhat

#pragma once
struct DoublyLinkedListNode {
	//creates node as a struct
public:
	DoublyLinkedListNode(double value, DoublyLinkedListNode* PREVIOUS = nullptr, DoublyLinkedListNode* NEXT = nullptr);
	int data;
	DoublyLinkedListNode* Previous;
	DoublyLinkedListNode* Next;
	//gives it data, and has a pointer backwards and forwards, since its
	//a doublylinkedlist
};