#pragma once
#include "Edge.h"
#include "AdjacencyLists.h"
#include "DisjointSets.h"
#include "MinHeap.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using std::vector;
using std::string;
using std::cin;
using std::ifstream;
using std::ios;
using std::endl;
using std::swap;
using std::ofstream;

//functions declaration
int partition(vector<Edge> &edges, int start, int end);
void quickSort(vector<Edge> &edges, int start, int end);
bool readDataFromFile(char* filepath, AdjacencyLists& Graph, int& n, int& m, Edge& edgeToRemove);
vector<Edge> KRUSKAL(AdjacencyLists& Graph);
vector<Pair*> PRIM(AdjacencyLists& Graph);
bool RemoveEdgeAndGetMSTByKruskal(AdjacencyLists& Graph, vector<Edge> edges, Edge& edgeToRemove, vector<Edge>& mst);
bool checkIfEdgeExist(vector<Edge> edges, Edge& edgeToFind);
vector<int> BFS(AdjacencyLists& Graph, int s);
bool checkIfLinkedGraph(vector<int> weights);
bool checkIfLinkedGraph(vector<Pair*> weights);
bool GetTreeWeight(vector<Edge> mst, int vertices, int& MSTweight);
bool GetTreeWeight(vector<Pair*> mst, int vertices, int& MSTweight);
void printMessage(const char* message, int* numToPrint, ofstream& outputFile);