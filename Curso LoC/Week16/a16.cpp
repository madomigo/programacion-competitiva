#include <bits/stdc++.h>
using namespace std;

vector<set<int>> graph;
vector<int> visited;

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    graph.resize(n + 1);
    visited.resize(n + 1);
    int num;
    for (int i = 1; i <= n; i++) {
        visited[i] = -1;
        for (int j = 1; j <= n; j++) {
            cin >> num;

            if (num == 1) {
                graph[i].insert(j);
            }
        }
    }

    queue<int> q;
    q.push(s);
    int x;
    visited[s] = 0;
    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (auto i : graph[x]) {
            if (visited[i] == -1) {
                visited[i] = visited[x] + 1;
                q.push(i);
            }
        }
    }

    if (visited[f] == -1) cout << 0;
    else cout << visited[f]; 
}