#include "DisjointSets.h"

DisjointSets::DisjointSets(int size)
{
	A.resize(size);
	for (int i = 0; i < A.size(); i++)
	{
		A[i].parent = -1;
		A[i].size = 0;
	}
}

void DisjointSets::MakeSet(int x)
{
	A[x].parent = x;
	A[x].size = 1;
}

int DisjointSets::Find(int x)
{
	if (A[x].parent == x)
		return x;
	else
		return (A[x].parent = Find(A[x].parent));
}

void DisjointSets::Union(int repx, int repy)
{
	if (A[repx].size > A[repy].size)
	{
		A[repy].parent = repx;
		A[repx].size += A[repy].size;
	}
	else
	{
		A[repx].parent = repy;
		A[repy].size += A[repx].size;
	}
}