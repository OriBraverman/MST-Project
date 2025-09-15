# MST Project

A comprehensive C++ implementation of Minimum Spanning Tree (MST) algorithms including Kruskal's and Prim's algorithms, with additional functionality to compute MST after edge removal.

## Project Overview

This project implements fundamental graph algorithms for finding Minimum Spanning Trees (MST) in weighted graphs. The program can:

1. Calculate MST using **Kruskal's algorithm**
2. Calculate MST using **Prim's algorithm** 
3. Calculate MST using **Kruskal's algorithm after removing a specified edge**

The implementation includes custom data structures such as disjoint sets (Union-Find), min-heap, adjacency lists, and graph representations optimized for MST operations.

## Algorithms Implemented

### Kruskal's Algorithm
- **Time Complexity**: O(E log E) where E is the number of edges
- **Approach**: Greedy algorithm that sorts edges by weight and uses Union-Find to avoid cycles
- **Data Structures Used**: Disjoint Sets (Union-Find), Edge sorting via QuickSort

### Prim's Algorithm  
- **Time Complexity**: O(V log V + E) where V is vertices and E is edges
- **Approach**: Greedy algorithm that grows MST from a starting vertex using a min-heap
- **Data Structures Used**: Min-Heap, Adjacency Lists

### Edge Removal Analysis
- Computes MST after removing a specified edge from the original graph
- Uses BFS to check graph connectivity after edge removal
- Applies Kruskal's algorithm on the modified graph if still connected

## File Structure

```
ProjectMST/
├── main.cpp              # Main program entry point
├── MSTFunctions.h/cpp    # Core MST algorithm implementations
├── Edge.h/cpp            # Edge class for graph representation
├── AdjacencyLists.h/cpp  # Graph representation using adjacency lists
├── DisjointSets.h/cpp    # Union-Find data structure for Kruskal's
├── Heap.h/cpp            # Base heap class
├── MinHeap.h/cpp         # Min-heap implementation for Prim's
├── List.h/cpp            # Linked list for adjacency list implementation
├── ListNode.h/cpp        # Node class for linked lists
├── Pair.h/cpp            # Utility class for vertex-weight pairs
└── ProjectMST.vcxproj    # Visual Studio project file
```

## Building and Compilation

### Prerequisites
- C++11 compatible compiler (g++, clang++, or Visual Studio)
- Standard C++ library

### Compilation Instructions

#### Using g++ (Linux/macOS/Windows with MinGW):
```bash
cd ProjectMST
g++ -o ProjectMST *.cpp -std=c++11
```

#### Using Visual Studio:
Open `ProjectMST.sln` in Visual Studio and build the solution.

## Usage

### Command Line Interface
```bash
./ProjectMST <input_file> <output_file>
```

**Parameters:**
- `input_file`: Path to file containing graph specification
- `output_file`: Path to file where results will be saved

### Input File Format

The input file must follow this exact format:

```
N               # Number of vertices
M               # Number of edges  
u1 v1 w1        # Edge 1: from vertex u1 to v1 with weight w1
u2 v2 w2        # Edge 2: from vertex u2 to v2 with weight w2
...
uM vM wM        # Edge M: from vertex uM to vM with weight wM
ur vr           # Edge to remove: from vertex ur to vr
```

**Important Notes:**
- Vertices are numbered from 1 to N (1-indexed)
- Edge weights can be negative
- The graph should be undirected (edges work both ways)
- Duplicate edges are not allowed

### Example Input File

```
4
5
1 2 1
2 3 2  
3 4 3
4 1 4
2 4 5
1 2
```

This represents:
- 4 vertices (numbered 1-4)
- 5 edges with weights
- Edge (1,2) should be removed for the third analysis

### Output Format

The program outputs three lines:
```
Kruskal <weight>     # MST weight using Kruskal's algorithm
Prim <weight>        # MST weight using Prim's algorithm  
Kruskal2 <weight>    # MST weight using Kruskal's after edge removal
```

If no MST exists (disconnected graph), the output shows:
```
Kruskal NO MST
Prim NO MST
Kruskal2 NO MST
```

### Example Run

```bash
# Create sample input
echo "4
5
1 2 1
2 3 2
3 4 3
4 1 4
2 4 5
1 2" > sample_input.txt

# Run the program
./ProjectMST sample_input.txt results.txt

# View results
cat results.txt
```

**Expected Output:**
```
Kruskal 6
Prim 6
Kruskal2 9
```

## Algorithm Details

### Kruskal's Algorithm Implementation
1. **Edge Sorting**: Uses QuickSort to sort edges by weight in ascending order
2. **Union-Find**: Implements path compression and union by rank for efficient cycle detection
3. **Greedy Selection**: Iteratively adds minimum weight edges that don't create cycles

### Prim's Algorithm Implementation  
1. **Min-Heap**: Custom min-heap implementation for efficient minimum vertex extraction
2. **Adjacency Lists**: Graph representation optimized for neighbor traversal
3. **Key Updates**: Decreases key values in heap when shorter paths are found

### Graph Connectivity Check
- **BFS Implementation**: Breadth-First Search to verify graph connectivity
- **Edge Removal**: Temporarily removes specified edge and checks if graph remains connected
- **Fallback**: Returns "NO MST" if graph becomes disconnected

## Data Structures

### Custom Implementations
- **DisjointSets**: Union-Find with path compression and union by rank
- **MinHeap**: Binary min-heap with decrease-key operation
- **AdjacencyLists**: Efficient graph representation for sparse graphs
- **Edge**: Lightweight edge representation with source, destination, and weight

### Memory Management
- Proper cleanup of dynamically allocated Pair objects in Prim's algorithm
- Automatic memory management for most data structures
- No memory leaks in normal execution paths

## Error Handling

The program includes comprehensive error handling for:
- **Invalid Command Line Arguments**: Requires exactly 2 arguments
- **File Access Errors**: Checks if input/output files can be opened
- **Input Format Validation**: Validates vertex indices and edge counts
- **Graph Consistency**: Checks for duplicate edges and invalid vertex numbers
- **Connectivity Analysis**: Detects disconnected graphs

## Performance Characteristics

### Time Complexity
- **Kruskal's**: O(E log E) due to edge sorting
- **Prim's**: O(V log V + E) with binary heap implementation
- **Overall**: O(E log E) dominated by sorting in Kruskal's algorithm

### Space Complexity  
- **Graph Storage**: O(V + E) for adjacency list representation
- **Auxiliary Space**: O(V) for Union-Find and heap structures
- **Overall**: O(V + E) space complexity

## Testing

### Test Cases Included
The repository includes functionality to test with various graph types:
- **Connected Graphs**: Standard MST computation
- **Disconnected Graphs**: Proper "NO MST" detection  
- **Single Vertex**: Edge case handling
- **Negative Weights**: Algorithm correctness with negative edge weights

### Creating Test Cases
```bash
# Simple connected graph
echo "3
3
1 2 1
2 3 2
1 3 3
1 2" > test_connected.txt

# Disconnected graph  
echo "4
2
1 2 1
3 4 2
1 2" > test_disconnected.txt
```

## Contributing

When contributing to this project:
1. Maintain the existing code style and structure
2. Add appropriate error handling for new features
3. Test with various graph configurations
4. Update documentation for any API changes

## License

This project is developed for educational purposes as part of computer science coursework focusing on graph algorithms and data structures.

## Technical Notes

- **Compiler Compatibility**: Requires C++11 or later for vector initialization and range-based loops
- **Platform Support**: Cross-platform compatible (Windows, Linux, macOS)
- **Dependencies**: Only standard C++ library, no external dependencies required
- **Memory Requirements**: Scales with O(V + E) memory usage based on graph size