#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> graph (n + 1);
    int fr, to;
    for (int i = 0; i < m; i++) {
        cin >> fr >> to;
        graph[fr].push_back(to);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
        for (auto x : graph[i]) cout << x << " ";
        cout << '\n';
    }

}