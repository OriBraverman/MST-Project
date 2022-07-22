#pragma once
#include "ListNode.h"
#include <iostream>


class List
{
	ListNode* head;
	ListNode* tail;

public:
	List()=default;
	~List()=default;
	void makeEmpty();
	bool isEmpty();
	bool isExist(int key);
	ListNode* Find(int key) const;
	void RemoveNodeByKeyFromList(int key);
	void insertDataToEndList(Pair data);
	void insertNodeToEndList(ListNode* newTail);
	ListNode* first()const;
	ListNode* last()const;
	void print();
};
