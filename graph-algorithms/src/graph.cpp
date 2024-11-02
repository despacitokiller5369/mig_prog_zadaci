#include "graph.h"

#include <iostream>

using namespace std;

GraphAdjList::GraphAdjList(int V) {
    this->V = V;
    adj.resize(V);
    capacity.resize(V, vector<int>(V, 0));
}

void GraphAdjList::addEdge(int u, int v, int capacity) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    this->capacity[u][v] = capacity;
}

bool GraphAdjList::bfs(int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int GraphAdjList::dfs(int u, int t, int flow, vector<int>& parent) {
    if (u == t) return flow;
    for (int v : adj[u]) {
        if (parent[v] == -1 && capacity[u][v] > 0) {
            parent[v] = u;
            int curr_flow = min(flow, capacity[u][v]);
            int temp_flow = dfs(v, t, curr_flow, parent);
            
            if (temp_flow > 0) {
                capacity[u][v] -= temp_flow;
                capacity[v][u] += temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int GraphAdjList::solveFordFulkerson(int s, int t) {
    vector<int> parent(V);
    int u, v;
    int max_flow = 0;

    while (bfs(s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int GraphAdjList::solveEdmondsKarp(int s, int t) {
    vector<int> parent(V);
    int u, v;
    int max_flow = 0;

    while (bfs(s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int GraphAdjList::solveDinic(int s, int t) {
    vector<int> level(V), parent(V);
    int max_flow = 0;

    while (bfs(s, t, level)) {
        parent.assign(V, -1);
        while (true) {
            int flow = dfs(s, t, INT_MAX, parent);
            if (flow == 0) break;
            max_flow += flow;
        }
    }
    return max_flow;
}

void GraphAdjList::minCut(int s, int t) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v] && capacity[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << "Min Cut Edges:" << endl;
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            if (visited[u] && !visited[v] && capacity[u][v] == 0) {
                cout << u << " - " << v << endl;
            }
        }
    }
}

GraphAdjMatrix::GraphAdjMatrix(int V) {
    this->V = V;
    capacity.resize(V, vector<int>(V, 0));
}

void GraphAdjMatrix::addEdge(int u, int v, int capacity) {
    this->capacity[u][v] = capacity;
}

bool GraphAdjMatrix::bfs(int s, int t, vector<int>& parent) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int GraphAdjMatrix::dfs(int u, int t, int flow, vector<int>& parent) {
    if (u == t) return flow;
    for (int v = 0; v < V; v++) {
        if (parent[v] == -1 && capacity[u][v] > 0) {
            parent[v] = u;
            int curr_flow = min(flow, capacity[u][v]);
            int temp_flow = dfs(v, t, curr_flow, parent);
            if (temp_flow > 0) {
                capacity[u][v] -= temp_flow;
                capacity[v][u] += temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int GraphAdjMatrix::solveDinic(int s, int t) {
    vector<int> parent(V), level(V);
    int max_flow = 0;

    while(bfs(s, t, level)) {
        parent.assign(V, -1);
        while(true) {
            int flow = dfs(s, t, INT_MAX, parent);
            if (flow == 0) break;
            max_flow += flow;
        }
    }
    return max_flow;
}

int GraphAdjMatrix::solveFordFulkerson(int s, int t) {
    vector<int> parent(V);
    int u, v;
    int max_flow = 0;

    while (bfs(s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int GraphAdjMatrix::solveEdmondsKarp(int s, int t) {
    vector<int> parent(V);
    int u, v;
    int max_flow = 0;

    while (bfs(s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

void GraphAdjMatrix::minCut(int s, int t) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && capacity[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << "Min Cut Edges:" << endl;
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (visited[u] && !visited[v] && capacity[u][v] == 0) {
                cout << u << " - " << v << endl;
            }
        }
    }
}