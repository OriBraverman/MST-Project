#pragma once
#include "Pair.h"
class ListNode
{
	Pair data;
	ListNode* next;

public:
	ListNode() :data(), next(nullptr) {}
	ListNode(Pair _data, ListNode* _next = nullptr) : data(_data), next(_next) {}
	ListNode* getNext();
	void setNext(ListNode* nextNode);
	Pair getData();
	void insertAfter(ListNode* newNode);
	ListNode* deleteAfter();
};
