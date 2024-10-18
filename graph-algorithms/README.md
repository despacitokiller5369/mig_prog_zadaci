# Max Flow Graph Algorithms

This project implements various maximum flow algorithms in C++. The algorithms included are:

- **Ford-Fulkerson Method**
- **Edmonds-Karp Algorithm**
- **Dinic's Algorithm**

Two representations of graphs are provided:

- **Adjacency List**
- **Adjacency Matrix**

## Table of Contents

- [Installation](#installation)
- [Maximum Flow Algorithms](#maximum-flow-algorithms)


## Installation

To compile and run the code, ensure you have a C++ compiler (like g++) installed on your system. Clone this repository and navigate to the project directory:

```bash
git clone https://github.com/despacitokiller5369/mig_prog_zadaci.git
cd mig_prog_zadaci/graph_algorithms
mkdir build
cd build
cmake ..
cmake --build .
```

## Maximum Flow Algorithms

This project implements several algorithms to solve the maximum flow problem in flow networks. Below is a brief overview of each algorithm included in this implementation:

### 1. Ford-Fulkerson Method
The Ford-Fulkerson method computes the maximum flow in a flow network by finding augmenting paths from the source to the sink. It iteratively increases the flow along these paths until no more augmenting paths can be found. The complexity of the algorithm can vary depending on the method used to find augmenting paths, and it may not terminate if the capacities are irrational.

### 2. Edmonds-Karp Algorithm
The Edmonds-Karp algorithm is a specific implementation of the Ford-Fulkerson method that uses Breadth-First Search (BFS) to find the shortest augmenting paths. This approach guarantees that the algorithm terminates and runs in polynomial time. The time complexity of Edmonds-Karp is \(O(VE^2)\), where \(V\) is the number of vertices and \(E\) is the number of edges in the network.

### 3. Dinic's Algorithm
Dinic's algorithm improves upon the basic Ford-Fulkerson method by using a level graph and performing blocking flows. It constructs a level graph using BFS and then finds blocking flows using Depth-First Search (DFS). This method is particularly efficient for dense graphs, with a time complexity of \(O(V^2E)\). Dinic's algorithm is known for its speed and effectiveness in handling large flow networks.
