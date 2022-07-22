#include "Heap.h"

Heap::Heap(int numVertices)
{
	indices.resize(numVertices);
	items.resize(numVertices);
}

void Heap::MakeEmpty()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}

void Heap::DecreaseKey(int newKey, int index)
{
	items[index]->setWeight(newKey);
	fixHeapUp(index);
}

void Heap::BuildHeap(vector <Pair*> inputItems)
{
	for (int i = 0; i < items.size(); i++)
	{
		indices[i] = i;
		items[i] = new Pair(inputItems[i]->getVertex(), inputItems[i]->getWeight());
	}
	for (int i = items.size()/2 -1; i >= 0; i--)
	{
		fixHeap(i);
	}
}

bool Heap::IsEmpty()
{
	return items.size() == 0;
}

void Heap::Insert(Pair* newPair)
{
	items.push_back(newPair);
	fixHeapUp(items.size() - 1);
}

void Heap::fixHeapUp(int currIndex)
{
	bool inGoodPosition = false;
	while (currIndex != 0 && !inGoodPosition)
	{
		if (compare(items[currIndex]->getWeight(), items[getParentIndex(currIndex)]->getWeight()))
		{
			swap(*items[currIndex], *items[getParentIndex(currIndex)]);
			currIndex = getParentIndex(currIndex);
		}
		else
			inGoodPosition = true;
	}
}

Pair* Heap::deleteByIndex(int startIndex)
{
	Pair* returned;
	if (IsEmpty())
		return nullptr;
	swap(*items[items.size() - 1], *items[startIndex]);
	returned = items[items.size() - 1];
	items[items.size() - 1] = nullptr;
	items.resize(items.size() - 1);
	items.shrink_to_fit();
	fixHeap(startIndex);
	return returned;
}

const Pair* Heap::getRoot() const
{
	if (items.size() != 0)
		return items[0];
	else
		return nullptr;
}

void Heap::fixHeap(int startIndex)
{
	int currIndex = startIndex;
	while (getLeftChildIndex(currIndex) != -1)
	{
		//there is only left child && left child < parent
		if (getRightChildIndex(currIndex) == -1 && 
			compare(items[getLeftChildIndex(currIndex)]->getWeight(), items[currIndex]->getWeight()))
		{
			swap(*items[currIndex], *items[getLeftChildIndex(currIndex)]);
			currIndex = getLeftChildIndex(currIndex);
		}
		//there are both son && left child <|> right child && left child <|> parent  ==> swap(left,parent)
		else if (getRightChildIndex(currIndex) != -1 &&
			compare(items[getLeftChildIndex(currIndex)]->getWeight(), items[getRightChildIndex(currIndex)]->getWeight()) &&
			compare(items[getLeftChildIndex(currIndex)]->getWeight(), items[currIndex]->getWeight()))
		{
			swap(*items[currIndex], *items[getLeftChildIndex(currIndex)]);
			currIndex = getLeftChildIndex(currIndex);
		}
		//there are both son && right child <|> left child && right child <|> parent  ==> swap(right,parent)
		else if (getRightChildIndex(currIndex) != -1 &&
			compare(items[getRightChildIndex(currIndex)]->getWeight(), items[getLeftChildIndex(currIndex)]->getWeight()) &&
			compare(items[getRightChildIndex(currIndex)]->getWeight(), items[currIndex]->getWeight()))
		{
			swap(*items[currIndex], *items[getRightChildIndex(currIndex)]);
			currIndex = getRightChildIndex(currIndex);
		}
		else
			return;
	}
}

void Heap::swap(Pair& item1, Pair& item2)
{
	int& item1Index = indices[item1.getVertex()];
	int& item2Index = indices[item2.getVertex()];
	std::swap(item1Index, item2Index);
	std::swap(item1, item2);
}

int Heap::getVertexIndex(int v)
{
	return indices[v];
}

int Heap::getSize()
{
	return items.size();
}

int Heap::getLeftChildIndex(int parent)
{
	int leftChildIndex = 2 * parent + 1;
	if (leftChildIndex < items.size())
		return leftChildIndex;
	else
	{
		return -1;
	}
}

int Heap::getRightChildIndex(int parent)
{
	int rightChildIndex = 2 * parent + 2;
	if (rightChildIndex < items.size())
		return rightChildIndex;
	else
	{
		return -1;
	}
}

int Heap::getParentIndex(int child)
{
	if (child == 0)
		return -1;
	return (child - 1) / 2;
}

Heap::~Heap()
{
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
}
