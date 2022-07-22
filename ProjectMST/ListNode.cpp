#include "ListNode.h"

void ListNode::insertAfter(ListNode* newNode)
{
	newNode->next = next;
	next = newNode;
}
ListNode* ListNode::deleteAfter()
{
	ListNode* toDelete = next;
	if (toDelete == nullptr)
	{
		return toDelete;
	}
	next = toDelete->next;
	return toDelete;
}

ListNode* ListNode::getNext()
{
	return next;
}
Pair ListNode::getData()
{
	return data;
}
void ListNode::setNext(ListNode* nextNode)
{
	next = nextNode;
}