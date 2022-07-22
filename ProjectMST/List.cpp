#include "List.h"

void List::makeEmpty()
{
	ListNode* curr = head, * tmp;
	while (curr != nullptr)
	{
		tmp = curr->getNext();
		curr->~ListNode();
		curr = tmp;
	}
}

bool List::isEmpty()
{
	return head == nullptr;
}

ListNode* List::first() const
{
	return head;
}

ListNode* List::last() const
{
	return tail;
}

void List::print()
{
	ListNode* curr = head;
	while (curr != nullptr)
	{
		std::cout << curr->getData() << " ";
	}
	std::cout << std::endl;
}

bool List::isExist(int key)
{
	ListNode* curr = head;
	while (curr != nullptr)
	{
		if (curr->getData().getVertex() == key)
			return true;
		curr = curr->getNext();
	}
	return false;
}

ListNode* List::Find(int key) const
{
	ListNode* curr = head;
	int currKey;
	while (curr != nullptr)
	{
		currKey = curr->getData().getVertex();
		if (currKey == key)
			return curr;
		curr = curr->getNext();
	}

	return nullptr;
}

void List::RemoveNodeByKeyFromList(int key)
{
	ListNode* after;
	ListNode* nodeToRemove = Find(key);
	if (head == tail)/*if list have 1 node*/
	{
		head = tail = nullptr;
	}
	else if (head == nodeToRemove)/*if node in head list*/
	{
		head = nodeToRemove->getNext();
	}
	else if (tail == nodeToRemove)/*if node in list tail*/
	{
		after = head;
		while (after->getNext() != nodeToRemove)
		{
			after = after->getNext();
		}
		tail = after;
		tail->setNext(nullptr);
	}
	else/*if node is in the middle*/
	{
		after = head;
		while (after->getNext() != nodeToRemove)
		{
			after = after->getNext();
		}
		after->setNext(nodeToRemove->getNext());
	}
	free(nodeToRemove);
}


void List::insertDataToEndList(Pair data)
{
	ListNode* newTail;
	newTail = new ListNode(data, nullptr);
	insertNodeToEndList(newTail);
}

void List::insertNodeToEndList(ListNode* newTail)
{
	if (isEmpty())
	{
		head = tail = newTail;
	}
	else
	{
		tail->setNext(newTail);
		tail = newTail;
	}
	tail->setNext(nullptr);
}
