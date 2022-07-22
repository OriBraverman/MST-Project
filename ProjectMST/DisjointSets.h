#pragma once
#include <vector>
#include<iostream>
using std::vector;

typedef struct element
{
	int parent;
	int size;
}Element;

class DisjointSets
{
	vector <Element> A;
public:
	DisjointSets(int size);
	void MakeSet(int x);
	int Find(int x);
	void Union(int repx, int repy);

};
