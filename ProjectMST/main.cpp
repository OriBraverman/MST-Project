#include "MSTFunctions.h"



// Calculate the MST weights of a given tree according to KRUSKAL and PRIM algorithms,
// as well as the MST weight after removing an edge from the tree (calculated using KRUKSAL).
// The program prints the result to the console and saves them in a file specified by the second input argument.
// The program should be called with two input argument:
// 1. A file path pointing to a file which specifies the tree's vertices, edges and weights.
// 2. A file path to the results file.
//
// The first input file format is as follows:
// - A line with the number of vertices N.
// - A line with the number of edges M.
// - M lines, each containing 3 integers representing a tree edge:
//   - The source vertex index (between 1 and N)
//   - The target vertex index (between 1 and N)
//   - The edge weight (can be negative).
// - A line with 2 integers representing the edge to remove:
//   - The source vertex index (between 1 and N)
//   - The target vertex index (between 1 and N)
int main(int argc, char* argv[])
{
	 vector<Edge> mstKruskal;
	 vector<Edge> mstKruskal2;
	 vector<Pair*> mstPrim;
	 AdjacencyLists Graph;
	 int n, m, MSTWeight, MSTWeightAfterEdgeRemove;
	 Edge edgeToRemove;
	 bool success;

	 if (argc != 3)
	 {
		 cout << "invalid input!" << endl;
		 exit(1);
	 }
	 bool readSuccess = readDataFromFile(argv[1], Graph, n, m, edgeToRemove);
	 if (!readSuccess)
	 {
		 exit(1);
	 }

	 ofstream outputFile(argv[2], ios::out);
	 if (!outputFile)
	 {
		 cout << "Invalid input! Results file could not be opened!" << endl;
		 exit(1);
	 }
	 mstKruskal = KRUSKAL(Graph);
	 if (GetTreeWeight(mstKruskal, n, MSTWeight))
	 {
		 printMessage("Kruskal " , &MSTWeight, outputFile);
	 }
	 else
	 {
		 printMessage("Kruskal NO MST", nullptr, outputFile);
	 }
	 mstPrim = PRIM(Graph);
	 if (GetTreeWeight(mstPrim, n, MSTWeight))
	 {
		 printMessage("Prim " , &MSTWeight, outputFile);

	 }
	 else
	 {
		 printMessage("Prim NO MST", nullptr,  outputFile);
	 }
	 for (int i = 0; i < mstPrim.size(); i++)
		 delete mstPrim[i];
	  success = RemoveEdgeAndGetMSTByKruskal(Graph, mstKruskal, edgeToRemove, mstKruskal2);
	 if (success && GetTreeWeight(mstKruskal2, n, MSTWeight))
	 {
		 printMessage("Kruskal2 " , &MSTWeight, outputFile);
	 }
	 else
	 {
		 printMessage("Kruskal2 NO MST", nullptr, outputFile);

	 }
	 outputFile.close();
	 return 0;
}