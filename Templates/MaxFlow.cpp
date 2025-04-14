// Max Flow using Dinic's algorithm

// Definición de la arista para el grafo de flujo.
struct Edge {
    int to, cap, rev;
};


// Función para agregar aristas (doble sentido para flujo residual)
void addEdge(vector<vector<Edge>> &grafo, int origen, int destino, int capacidad) {
    grafo[origen].push_back({destino, capacidad, grafo[destino].size()});
    grafo[destino].push_back({origen, 0, grafo[origen].size()-1});
}

int dfs (int v, int t, int f, vi &nivel, vi &iter, vector<vector<Edge>> &grafo) {
    if (v == t) return f;
    for (int i = iter[v]; i < grafo[v].size(); i++) {
        Edge &e = grafo[v][i];
        if (e.cap > 0 && nivel[v] < nivel[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap), nivel, iter, grafo);
            if (d > 0) {
                e.cap -= d;
                grafo[e.to][e.rev].cap += d;
                return d;
            }
        }
        iter[v]++;
    }
    return 0;
}



int maxFlow(int s, int t, vector<vector<Edge>> &grafo) {
    int flow = 0;
    while (true) {
        vi nivel(grafo.size(), -1);
        queue<int> q;
        nivel[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto edge : grafo[v]) {
                if (edge.cap > 0 && nivel[edge.to] < 0) {
                    nivel[edge.to] = nivel[v] + 1;
                    q.push(edge.to);
                }
            }
        }

        if (nivel[t] < 0) break;
        vi iter(grafo.size(), 0);
        while (int f = dfs(s,t,INF,nivel, iter, grafo))
            flow += f;
    }
    return flow;
}
