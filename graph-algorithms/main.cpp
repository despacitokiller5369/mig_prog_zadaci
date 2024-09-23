    #include <iostream>
    #include <climits>
    #include <cstring>
    #include <queue>
    #include <vector>

    using namespace std;

    class GraphAdjList {
    public:
        int V;
        vector<vector<int>> adj;
        vector<vector<int>> capacity;

        // Konstruktor za graf so daden broj na teminja
        GraphAdjList(int V) {
            this->V = V;
            adj.resize(V);
            capacity.resize(V, vector<int>(V, 0));
        }

        // Soglasno dodavame novo teme so negov sosed i soodvetno setirame kapacitetot na temeto
        void addEdge(int u, int v, int capacity) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            this->capacity[u][v] = capacity;
        }

        // Standarden bfs algoritam za prebaruvanje
        bool bfs(int s, int t, int parent[]) {
            bool visited[V];
            memset(visited, false, sizeof(visited));
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

        int dfs(int u, int t, int flow, int parent[]) {
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

        // Ford Fulkerson algoritam so bfs
        int solveFordFulkerson(int s, int t) {
            int u, v;
            int parent[V];
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

        // Edmonds Karp algoritam
        int solveEdmondsKarp(int s, int t) {
            int u, v;
            int parent[V];
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

        // Dinic algoritam
        int solveDinic(int s, int t) {
            int max_flow = 0;
            int level[V];
            int parent[V];

            while (bfs(s, t, level)) {
                memset(parent, -1, sizeof(parent));
                while (true) {
                    int flow = dfs(s, t, INT_MAX, parent);
                    if (flow == 0) break;
                    max_flow += flow;
                }
            }
            return max_flow;
        }

        void minCut(int s, int t) {
            int maxFlow = solveEdmondsKarp(s, t);
            cout << "Max Flow: " << maxFlow << endl;

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
    };

    class GraphAdjMatrix {
    public:
        int **capacity;
        int V;

        // Konstruktor za graf so daden broj na teminja
        GraphAdjMatrix(int V) {
            this->V = V;
            capacity = new int*[V];
            for (int i = 0; i < V; i++) {
                capacity[i] = new int[V];
                memset(capacity[i], 0, V * sizeof(int));
            }
        }

        // Soglasno dodavame novo teme so negov sosed i soodvetno setirame kapacitetot na temeto
        void addEdge(int u, int v, int capacity) {
            this->capacity[u][v] = capacity;
        }

        // Standarden bfs algoritam za prebaruvanje
        bool bfs(int s, int t, int parent[]) {
            bool visited[V];
            memset(visited, false, sizeof(visited));
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

        int dfs(int u, int t, int flow, int parent[]) {
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

        int solveDinic(int s, int t) {
            int max_flow = 0;
            int level[V];
            int parent[V];

            while(bfs(s, t, level)) {
                memset(parent, -1, sizeof(parent));
                while(true) {
                    int flow = dfs(s, t, INT_MAX, parent);
                    if (flow == 0) break;
                    max_flow += flow;
                }
            }
            return max_flow;
        }

        // Ford Fulkerson algoritam so bfs
        int solveFordFulkerson(int s, int t) {
            int u, v;
            int parent[V];
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

        // Edmonds Karp algoritam
        int solveEdmondsKarp(int s, int t) {
            int u, v;
            int parent[V];
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

        // Min Cut algoritam
        void minCut(int s, int t) {
            int maxFlow = solveEdmondsKarp(s, t);
            cout << "Max Flow: " << maxFlow << endl;

            bool* visited = new bool[V];
            memset(visited, false, sizeof(bool) * V);
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

            delete[] visited;
        }

        ~GraphAdjMatrix() {
            for (int i = 0; i < V; i++) {
                delete[] capacity[i];
            }
            delete[] capacity;
        }
    };

    int main() {
        // Using adjacency matrix with Edmonds-Karp algorithm
        GraphAdjMatrix g1(6);
        g1.addEdge(0, 1, 16);
        g1.addEdge(0, 2, 13);
        g1.addEdge(1, 2, 10);
        g1.addEdge(1, 3, 12);
        g1.addEdge(2, 1, 4);
        g1.addEdge(2, 4, 14);
        g1.addEdge(3, 2, 9);
        g1.addEdge(3, 5, 20);
        g1.addEdge(4, 3, 7);
        g1.addEdge(4, 5, 4);

        cout << "Max Flow (Adjacency Matrix and Edmonds-Karp): " << g1.solveEdmondsKarp(0, 5) << endl;
        g1.minCut(0, 5);

        // Using adjacency matrix with Ford-Fulkerson algorithm
        GraphAdjMatrix g2(6);
        g2.addEdge(0, 1, 16);
        g2.addEdge(0, 2, 13);
        g2.addEdge(1, 2, 10);
        g2.addEdge(1, 3, 12);
        g2.addEdge(2, 1, 4);
        g2.addEdge(2, 4, 14);
        g2.addEdge(3, 2, 9);
        g2.addEdge(3, 5, 20);
        g2.addEdge(4, 3, 7);
        g2.addEdge(4, 5, 4);

        cout << "Max Flow (Adjacency Matrix and Ford-Fulkerson): " << g2.solveFordFulkerson(0, 5) << endl;
        g2.minCut(0, 5);

        // Using adjacency list with Edmonds-Karp algorithm
        GraphAdjList g3(6);
        g3.addEdge(0, 1, 16);
        g3.addEdge(0, 2, 13);
        g3.addEdge(1, 2, 10);
        g3.addEdge(1, 3, 12);
        g3.addEdge(2, 1, 4);
        g3.addEdge(2, 4, 14);
        g3.addEdge(3, 2, 9);
        g3.addEdge(3, 5, 20);
        g3.addEdge(4, 3, 7);
        g3.addEdge(4, 5, 4);

        cout << "Max Flow (Adjacency List and Edmonds-Karp): " << g3.solveEdmondsKarp(0, 5) << endl;
        g3.minCut(0, 5);

        // Using adjacency list with Ford-Fulkerson algorithm
        GraphAdjList g4(6);
        g4.addEdge(0, 1, 16);
        g4.addEdge(0, 2, 13);
        g4.addEdge(1, 2, 10);
        g4.addEdge(1, 3, 12);
        g4.addEdge(2, 1, 4);
        g4.addEdge(2, 4, 14);
        g4.addEdge(3, 2, 9);
        g4.addEdge(3, 5, 20);
        g4.addEdge(4, 3, 7);
        g4.addEdge(4, 5, 4);

        cout << "Max Flow (Adjacency List and Ford-Fulkerson): " << g4.solveFordFulkerson(0, 5) << endl;
        g4.minCut(0, 5);

        // Using adjacency matrix with Dinic's algorithm
        GraphAdjMatrix g5(6);
        g5.addEdge(0, 1, 16);
        g5.addEdge(0, 2, 13);
        g5.addEdge(1, 2, 10);
        g5.addEdge(1, 3, 12);
        g5.addEdge(2, 1, 4);
        g5.addEdge(2, 4, 14);
        g5.addEdge(3, 2, 9);
        g5.addEdge(3, 5, 20);
        g5.addEdge(4, 3, 7);
        g5.addEdge(4, 5, 4);

        cout << "Max Flow (Adjacency Matrix and Dinic's): " << g5.solveDinic(0, 5) << endl;
        g5.minCut(0, 5);

        // Using adjacency list with Dinic's algorithm
        GraphAdjList g6(6);
        g6.addEdge(0, 1, 16);
        g6.addEdge(0, 2, 13);
        g6.addEdge(1, 2, 10);
        g6.addEdge(1, 3, 12);
        g6.addEdge(2, 1, 4);
        g6.addEdge(2, 4, 14);
        g6.addEdge(3, 2, 9);
        g6.addEdge(3, 5, 20);
        g6.addEdge(4, 3, 7);
        g6.addEdge(4, 5, 4);

        cout << "Max Flow (Adjacency List and Dinic's): " << g6.solveDinic(0, 5) << endl;
        g6.minCut(0, 5);

        return 0;
    }
