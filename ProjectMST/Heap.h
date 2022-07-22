#pragma once
#include <iostream>
#include <vector>
#include "Pair.h"
using std::vector;
using std::cout;

// in this class Pair contains (key - weight, value- vertex)
class Heap
{
	vector<int> indices;
	vector<Pair*> items;
public:
	Heap(int numVertices);
	void MakeEmpty();
	void BuildHeap(vector <Pair*> inputItems);
	bool IsEmpty();
	void Insert(Pair* newPair);
	void fixHeapUp(int currIndex);
	void fixHeap(int startIndex);
	void swap(Pair& item1, Pair& item2);
	int getSize();
	int getLeftChildIndex(int parent);
	int getRightChildIndex(int parent);
	int getParentIndex(int child);
	Pair* deleteByIndex(int startIndex);
	void DecreaseKey(int newKey, int index); //assumption: newKey <= items[index].getData()
	int getVertexIndex(int v);
	~Heap();

protected:
	const Pair* getRoot() const;
	virtual bool compare(int key1, int key2) = 0;
};
