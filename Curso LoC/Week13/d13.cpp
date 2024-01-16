#include <bits/stdc++.h>
using namespace std;

vector<set<int>> graph;
vector<bool> visited;
vector<int> p;
int steps = 0;

void dfs (int x, int parent) {
    if (visited[x]) return;
    steps++;
    visited[x] = true;
    p[x] = parent;

    for (auto i : graph[x]){
        if (!visited[i]) {
            dfs (i, x);
        }

    }
}

int main () {
    int n;
    cin >> n;
    int aux = n;

    graph.resize(n + 1);
    visited.resize(n + 1);
    p.resize(n + 1);


    int fr, to;
    while (aux--) {  
        cin >> fr >> to;

        graph[fr].insert(to);
    }

    int mx = INT32_MIN;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        steps = 0;
        dfs(i, -1);
        mx = max(mx, steps);
    }

    cout << mx << '\n';
}