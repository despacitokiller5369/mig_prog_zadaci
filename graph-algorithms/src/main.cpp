#include <iostream>

#include "graph.h"

using namespace std;

int main() {
    // Using adjacency matrix with Edmonds-Karp algorithm
    Graph *g1 = new GraphAdjMatrix(6);
    g1->addEdge(0, 1, 16);
    g1->addEdge(0, 2, 13);
    g1->addEdge(1, 2, 10);
    g1->addEdge(1, 3, 12);
    g1->addEdge(2, 1, 4);
    g1->addEdge(2, 4, 14);
    g1->addEdge(3, 2, 9);
    g1->addEdge(3, 5, 20);
    g1->addEdge(4, 3, 7);
    g1->addEdge(4, 5, 4);

    cout << "Max Flow (Adjacency Matrix and Edmonds-Karp): " << g1->solveEdmondsKarp(0, 5) << endl;
    g1->minCut(0, 5);

    // Using adjacency matrix with Ford-Fulkerson algorithm
    Graph *g2 = new GraphAdjMatrix(6);
    g2->addEdge(0, 1, 16);
    g2->addEdge(0, 2, 13);
    g2->addEdge(1, 2, 10);
    g2->addEdge(1, 3, 12);
    g2->addEdge(2, 1, 4);
    g2->addEdge(2, 4, 14);
    g2->addEdge(3, 2, 9);
    g2->addEdge(3, 5, 20);
    g2->addEdge(4, 3, 7);
    g2->addEdge(4, 5, 4);

    cout << "Max Flow (Adjacency Matrix and Ford-Fulkerson): " << g2->solveFordFulkerson(0, 5) << endl;
    g2->minCut(0, 5);

    // Using adjacency list with Edmonds-Karp algorithm
    Graph *g3 = new GraphAdjList(6);
    g3->addEdge(0, 1, 16);
    g3->addEdge(0, 2, 13);
    g3->addEdge(1, 2, 10);
    g3->addEdge(1, 3, 12);
    g3->addEdge(2, 1, 4);
    g3->addEdge(2, 4, 14);
    g3->addEdge(3, 2, 9);
    g3->addEdge(3, 5, 20);
    g3->addEdge(4, 3, 7);
    g3->addEdge(4, 5, 4);

    cout << "Max Flow (Adjacency List and Edmonds-Karp): " << g3->solveEdmondsKarp(0, 5) << endl;
    g3->minCut(0, 5);

    // Using adjacency list with Ford-Fulkerson algorithm
    Graph *g4 = new GraphAdjList(6);
    g4->addEdge(0, 1, 16);
    g4->addEdge(0, 2, 13);
    g4->addEdge(1, 2, 10);
    g4->addEdge(1, 3, 12);
    g4->addEdge(2, 1, 4);
    g4->addEdge(2, 4, 14);
    g4->addEdge(3, 2, 9);
    g4->addEdge(3, 5, 20);
    g4->addEdge(4, 3, 7);
    g4->addEdge(4, 5, 4);

    cout << "Max Flow (Adjacency List and Ford-Fulkerson): " << g4->solveFordFulkerson(0, 5) << endl;
    g4->minCut(0, 5);

    // Using adjacency matrix with Dinic's algorithm
    Graph *g5 = new GraphAdjMatrix(6);
    g5->addEdge(0, 1, 16);
    g5->addEdge(0, 2, 13);
    g5->addEdge(1, 2, 10);
    g5->addEdge(1, 3, 12);
    g5->addEdge(2, 1, 4);
    g5->addEdge(2, 4, 14);
    g5->addEdge(3, 2, 9);
    g5->addEdge(3, 5, 20);
    g5->addEdge(4, 3, 7);
    g5->addEdge(4, 5, 4);

    cout << "Max Flow (Adjacency Matrix and Dinic's): " << g5->solveDinic(0, 5) << endl;
    g5->minCut(0, 5);

    // Using adjacency list with Dinic's algorithm
    Graph *g6 = new GraphAdjList(6);
    g6->addEdge(0, 1, 16);
    g6->addEdge(0, 2, 13);
    g6->addEdge(1, 2, 10);
    g6->addEdge(1, 3, 12);
    g6->addEdge(2, 1, 4);
    g6->addEdge(2, 4, 14);
    g6->addEdge(3, 2, 9);
    g6->addEdge(3, 5, 20);
    g6->addEdge(4, 3, 7);
    g6->addEdge(4, 5, 4);

    cout << "Max Flow (Adjacency List and Dinic's): " << g6->solveDinic(0, 5) << endl;
    g6->minCut(0, 5);

    return 0;
}
