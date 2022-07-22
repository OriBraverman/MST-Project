#include "AdjacencyLists.h"


void AdjacencyLists::MakeEmptyGraph(int n)
{
	graph.resize(n);
	for (int i = 0; i < n; i++)
		graph[i].makeEmpty();
}
//assumption: the arc is in both lists graph[u] and graph[v]
bool AdjacencyLists::IsAdjacent(int u, int v)
{
	return graph[u].isExist(v);
}
const List& AdjacencyLists::GetAdjList(int u) const
{
	return graph[u];
}
void AdjacencyLists::AddEdge(Edge newEdge)
{
	int u, v, weight;

	u = newEdge.getFrom();
	v = newEdge.getTo();
	weight = newEdge.getWeight();

	if (!graph[u].isExist(v))
	{
		graph[u].insertDataToEndList(Pair(v, weight));
		graph[v].insertDataToEndList(Pair(u, weight));
		E.push_back(newEdge);
	}
}

int AdjacencyLists::GetNumVertices()
{
	return graph.size();
}

vector<Edge>& AdjacencyLists::GetEdges()
{
	return E;
}

int AdjacencyLists::FindEdgeInVector(int u, int v)
{

	for (int i = 0; i < E.size(); i++)
	{

		if (E[i].getFrom() == u && E[i].getTo() == v)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

void AdjacencyLists::RemoveEdge(int u, int v)
{
	int edgeIndex = FindEdgeInVector(u, v);
	if (edgeIndex != NOT_FOUND)
	{
		E.erase(E.begin() + edgeIndex);
	}
	graph[u].RemoveNodeByKeyFromList(v);
	graph[v].RemoveNodeByKeyFromList(u);
}

int AdjacencyLists::GetNumEdges()
{
	return E.size();
}