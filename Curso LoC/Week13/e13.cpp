#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> order;

void dfs(int x) {
    visited[x] = true;

    for (auto i : graph[x]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    order.push_back(x);
}


int main () {
    int n, m;
    cin >> n >> m;
    
    graph.resize(n);
    visited.resize(n);

    int n1, n2;
    bool bad = false;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2;

        if (n1 == n2) bad = true;

        graph[n1].push_back(n2);
    }

    if (bad) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }

    }
    reverse(order.begin(), order.end());
    

    vector<int> ans (n);
    for (int i = 0; i < n; i++){
        ans[order[i]] = i + 1;
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
    
    for (int i = 0; i < n; i++) {
        for (auto x : graph[i]) {
            if (ans[i] > ans[x]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';

}