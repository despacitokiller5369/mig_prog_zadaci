#pragma once

#include <queue>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

class Graph {
public:
    virtual void addEdge(int u, int v, int capacity) = 0;
    virtual bool bfs(int s, int t, vector<int>& parent) = 0;
    virtual int dfs(int u, int t, int flow, vector<int>& parent) = 0;
    virtual int solveFordFulkerson(int s, int t) = 0;
    virtual int solveEdmondsKarp(int s, int t) = 0;
    virtual int solveDinic(int s, int t) = 0;
    virtual void minCut(int s, int t) = 0;
};

class GraphAdjList : public Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> capacity;
public:
    GraphAdjList(int V);
    void addEdge(int u, int v, int capacity);
    bool bfs(int s, int t, vector<int>& parent);
    int dfs(int u, int t, int flow, vector<int>& parent);
    int solveFordFulkerson(int s, int t);
    int solveEdmondsKarp(int s, int t);
    int solveDinic(int s, int t);
    void minCut(int s, int t);
};

class GraphAdjMatrix : public Graph {
    int V;
    vector<vector<int>> capacity;
public:
    GraphAdjMatrix(int V);
    void addEdge(int u, int v, int capacity);
    bool bfs(int s, int t, vector<int>& parent);
    int dfs(int u, int t, int flow, vector<int>& parent);
    int solveDinic(int s, int t);
    int solveFordFulkerson(int s, int t);
    int solveEdmondsKarp(int s, int t);
    void minCut(int s, int t);
};