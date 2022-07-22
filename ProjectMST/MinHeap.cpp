#include "MinHeap.h"

bool MinHeap::compare(int key1, int key2)
{
	return key1 < key2;
}

const Pair* MinHeap::getMin()
{
	return getRoot();
}

Pair* MinHeap::deleteMin()
{
	return deleteByIndex(0);
}
