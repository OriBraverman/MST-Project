#include "MSTFunctions.h"

bool readDataFromFile(char* filepath, AdjacencyLists& Graph, int& n, int& m, Edge& edgeToRemove)
{
	string line;
	int i, u , v, weight;
	char temp;
	ifstream GraphFile(filepath, ios::in);
	if (!GraphFile)
	{
		cout << "File could not be opened!" << endl;
		return false;
	}
	GraphFile >> n >> m;
	Graph.MakeEmptyGraph(n);
	i = 0;
	while (GraphFile >> u >> v >> weight && i < m)
	{
		if (u > n || v > n)
		{
			cout << "Invalid Input: Bad Number Of Vertices" << endl;
			GraphFile.close();
			return false;
		}
		if (Graph.FindEdgeInVector(u - 1, v - 1) == NOT_FOUND)
		{
			Graph.AddEdge(Edge(u - 1, v - 1, weight));
			i++;
		}
		else
		{
			cout << "Invalid Input" << endl;
			GraphFile.close();
			return false;
		}
	}
	if (i < m)
	{
		cout << "Invalid Input" << endl;
		GraphFile.close();
		return false;
	}
	if (GraphFile.eof())//the final edge to remove already recived in while
	{
		if (u > n || v > n)
		{
			cout << "Invalid Input: Bad Number Of Vertices" << endl;
			GraphFile.close();
			return false;
		}
		edgeToRemove.setFrom(u-1);
		edgeToRemove.setTo(v-1);
	}
	else 
	{
		cout << "Invalid Input" << endl;
		GraphFile.close();
		return false;
	}
	while (GraphFile >> temp)// Attempt read into temp, return false if it fails
	{	
		if ((temp != ' ') || (temp != '\n'))
		{
			cout << "ERROR: Graph couldn't loaded: There are too many edges!" << endl;
			GraphFile.close();
			return false;
		}
	}
	GraphFile.close();
	return true;
}

int partition(vector<Edge> &edges, int start, int end)
{

	Edge pivot = edges[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (edges[i].getWeight() <= pivot.getWeight())
			count++;
	}

	int pivotIndex = start + count;
	swap(edges[pivotIndex], edges[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (edges[i].getWeight() <= pivot.getWeight()) {
			i++;
		}

		while (edges[j].getWeight() > pivot.getWeight()) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(edges[i++], edges[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(vector<Edge> &edges, int start, int end)
{
	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(edges, start, end);

	// Sorting the left part
	quickSort(edges, start, p - 1);

	// Sorting the right part
	quickSort(edges, p + 1, end);
}

vector<Edge> KRUSKAL(AdjacencyLists& Graph)
{
	int i, u, v;
	vector<Edge> F;
	DisjointSets UF(Graph.GetNumVertices());
	vector <Edge> Edges;
	quickSort(Graph.GetEdges(), 0 ,Graph.GetNumEdges() - 1);
	Edges = Graph.GetEdges();

	for (i = 0; i < Graph.GetNumVertices(); i++)
	{
		UF.MakeSet(i);
	}

	for (const Edge& edge: Edges)
	{
		u = UF.Find(edge.getFrom());
		v = UF.Find(edge.getTo());
		if (u != v)
		{
			F.push_back(edge);
			UF.Union(u, v);
		}
	}
	return F;
}

vector<Pair*> PRIM(AdjacencyLists& Graph)
{
	int u, v, weightUv, numVertices = Graph.GetNumVertices();
	MinHeap Q(numVertices);
	List AdjList;
	ListNode* curr;
	vector<bool> InT(numVertices);
	vector<Pair*> minWeight(numVertices);
	vector<int> p(numVertices);

	minWeight[0]=new Pair(0, 0);
	p[0] = -1;

	for (int v = 1; v < numVertices; v++)
	{
		minWeight[v] = new Pair(v,INT_MAX);
		p[v] = -1;
	}

	Q.BuildHeap(minWeight);

	while (!Q.IsEmpty())
	{
		u = Q.deleteMin()->getVertex();
		InT[u] = true;
		AdjList = Graph.GetAdjList(u);
		curr = AdjList.first();
		while (curr != nullptr)
		{
			v = curr->getData().getVertex();
			weightUv = curr->getData().getWeight();
			if (!InT[v] && weightUv < minWeight[v]->getWeight())
			{
				minWeight[v]->setWeight(weightUv);
				p[v] = u;
				Q.DecreaseKey(weightUv, Q.getVertexIndex(v));
			}
			curr = curr->getNext();
		}
	}

	return minWeight;
}

bool checkIfEdgeExist(vector<Edge> edges, Edge& edgeToFind)
{
	for (const Edge& edge: edges)
	{
		if (edge.getFrom() == edgeToFind.getFrom() && edge.getTo() == edgeToFind.getTo())
		{
			return true;
		}
	}

	return false;
}

vector<int> BFS(AdjacencyLists& Graph, int s)
{
	int numVertices = Graph.GetNumVertices();
	vector<vector<int>> L(numVertices);
	vector<int> d(numVertices);
	ListNode* currNode;
	int v, i = 0;

	for (int ver = 0; ver < numVertices; ver++)
	{
		d[ver] = INT_MAX;
	}

	L[0].push_back(s);
	d[s] = 0;

	while (L[i].size() != 0)
	{
		for (int u = 0; u < L[i].size(); u++)
		{
			currNode = Graph.GetAdjList(L[i][u]).first();
			while (currNode != nullptr)
			{
				v = currNode->getData().getVertex();
				if (d[v] == INT_MAX)
				{
					d[v] = i + 1;
					L[i + 1].push_back(v);
				}
				currNode = currNode->getNext();
			}
		}
		
		i++;
	}
	return d;
}

bool checkIfLinkedGraph(vector<int> weights)
{
	for (int weight: weights)
	{
		if (weight == INT_MAX)
		{
			return false;
		}
	}

	return true;
}

bool checkIfLinkedGraph(vector<Pair*> pairs)
{
	for (Pair* pair : pairs)
	{
		if (pair->getWeight() == INT_MAX)
		{
			return false;
		}
	}

	return true;
}

bool checkIfLinkedGraph(vector<Edge> edges)
{
	for (const Edge& edge : edges)
	{
		if (edge.getWeight() == INT_MAX)
		{
			return false;
		}
	}

	return true;
}

bool RemoveEdgeAndGetMSTByKruskal(AdjacencyLists& Graph, vector<Edge> edges, Edge& edgeToRemove, vector<Edge>& mst)
{
	bool edgeToRemoveInEdges, isLinkedGraph;
	vector<int> weights;

	edgeToRemoveInEdges = checkIfEdgeExist(edges, edgeToRemove);

	if (!edgeToRemoveInEdges)
	{
		mst = edges;
		return true;
	}

	Graph.RemoveEdge(edgeToRemove.getFrom(), edgeToRemove.getTo());
	weights = BFS(Graph, 0);
	isLinkedGraph = checkIfLinkedGraph(weights);

	if (isLinkedGraph)
	{
		mst = KRUSKAL(Graph);
		return true;
	}
	else
	{
		return false;
	}
}

bool GetTreeWeight(vector<Edge> mst, int vertices, int& MSTweight)
{
	int totalWeight = 0;
	if (!checkIfLinkedGraph(mst) || mst.size() < vertices - 1)
	{
		return false;
	}
	for (const Edge& edge: mst)
	{
		totalWeight += edge.getWeight();
	}

	MSTweight = totalWeight;
	return true;
}

bool GetTreeWeight(vector<Pair*> mst, int vertices, int& MSTweight)
{
	int totalWeight = 0;
	if (!checkIfLinkedGraph(mst) || mst.size() < vertices - 1)
	{
		return false;
	}
	for (Pair* edge : mst)
	{
		totalWeight += edge->getWeight();
	}
	MSTweight = totalWeight;
	return true;
}

void printMessage(const char* message, int* numToPrint,  ofstream& outputFile)
{
	if (numToPrint == nullptr)
	{
		cout << message << endl;
		outputFile << message << endl;
	}
	else
	{
		cout << message << *numToPrint << endl;
		outputFile << message << *numToPrint << endl;
	}
}
