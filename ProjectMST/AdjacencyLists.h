#pragma once
#include "List.h"
#include "Edge.h"
#include <vector>
using std::vector;
#define NOT_FOUND -1

// in this class Pair contains (key - vertex, weight- value)
class AdjacencyLists
{
	vector<Edge> E;
	vector<List> graph;
public:
	AdjacencyLists() =default;
	~AdjacencyLists()=default;
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v);
	vector<Edge>& GetEdges();
	int GetNumVertices();
	const List& GetAdjList(int u) const;
	void AddEdge(Edge newEdge);
	void RemoveEdge(int u, int v);
	int FindEdgeInVector(int u, int v);
	int GetNumEdges();
};