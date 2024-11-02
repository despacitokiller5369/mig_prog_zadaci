# mig_prog_zadaci

Welcome to the **mig_prog_zadaci** repository! This project is a collection of tasks and implementations focused on graph and string algorithms, created primarily for academic purposes. The repository includes various algorithms and implementations that are helpful for solving problems in these domains.



# Overview of Algorithms

## Graph Algorithms

- **Ford-Fulkerson**: This method computes the maximum flow in a flow network. It uses a path-finding technique to incrementally increase the flow until no more augmenting paths are found.

- **Edmonds-Karp**: An implementation of the Ford-Fulkerson method that uses BFS to find the shortest augmenting path. This algorithm ensures polynomial time complexity.

- **Dinic's Algorithm**: This algorithm improves on the Edmonds-Karp method by using level graphs and blocking flows to achieve better performance, especially in networks with large capacities.

Each algorithm is implemented using two different graph representations:
- **Adjacency List**: Efficient for sparse graphs.
- **Adjacency Matrix**: Useful for dense graphs or when quick edge lookups are required.


## String Processing
A custom String class has been implemented with several string-processing algorithms, including substring searching with the Knuth-Morris-Pratt (KMP) algorithm. The key functionalities are:

- **KMP Full Match (findAllSubStr):** Finds all occurrences of a substring within the string.
- **KMP First Match (findFirstSubStr):** Finds the first occurrence of a substring within the string.
- **KMP Reverse Search (findLastSubStr):** Searches for the substring from the end, effectively reversing the KMP algorithm.

These methods optimize substring search by preprocessing the pattern, allowing efficient matching.