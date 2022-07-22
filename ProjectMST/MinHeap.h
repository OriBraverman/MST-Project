#pragma once
#include "Heap.h"

class MinHeap : public Heap
{
	virtual bool compare(int key1, int key2);
public:
	MinHeap(int numVertices) :Heap(numVertices) {}
	const Pair* getMin();
	Pair* deleteMin();
};
