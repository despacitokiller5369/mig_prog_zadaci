# mig_prog_zadaci

Welcome to the **mig_prog_zadaci** repository! This project is a collection of tasks and implementations focused on graph algorithms, created primarily for academic purposes. The repository includes various algorithms and their implementations, which can be useful for understanding and solving problems related to graphs.

## Overview of Algorithms

- **Ford-Fulkerson**: This method computes the maximum flow in a flow network. It uses a path-finding technique to incrementally increase the flow until no more augmenting paths are found.

- **Edmonds-Karp**: An implementation of the Ford-Fulkerson method that uses BFS to find the shortest augmenting path. This algorithm ensures polynomial time complexity.

- **Dinic's Algorithm**: This algorithm improves on the Edmonds-Karp method by using level graphs and blocking flows to achieve better performance, especially in networks with large capacities.

Each algorithm is implemented using two different graph representations:
- **Adjacency List**: Efficient for sparse graphs.
- **Adjacency Matrix**: Useful for dense graphs or when quick edge lookups are required.