#include <bits\stdc++.h>
using namespace std;
#define int long long
    
int n, m;
vector<set<int>> graph;
vector<bool> visited;
vector<int> color;

bool Bipartite(int x) {
    for (auto i : graph[x]) {
        if (!visited[i]) {
            visited[i] = true;
            
            if (color[x] == 0) color[i] = 1;
            else color[i] = 0;

            if (!Bipartite(i)) return false;
        }

        else if (color[x] == color[i]) return false;

    }
    return true;
}

int32_t main () {
    cin >> n >> m;  

    graph.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++) visited[i] = false;
    color.resize(n + 1);


    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;

        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }

    visited[1] = true;
    color[1] = 0;

    if (Bipartite(1)) {
        int unos = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) unos++;
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) sum += (unos - graph[i].size());
        }

        cout << sum << '\n';
    }

    else cout << "-1\n";

}