#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> graph (n + 1);
    int fr, to;
    for (int i = 0; i < m; i++) {
        cin >> fr >> to;

        if (find(graph[fr].begin(), graph[fr].end(), to) == graph[fr].end()) {
            graph[fr].push_back(to);
            graph[to].push_back(fr);
        }
    }

    bool complete = true;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() != n - 1) {
            complete = false;
            break;
        }
    }

    cout << (complete ? "YES\n" : "NO\n");

}
