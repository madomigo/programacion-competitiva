#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<vector<int>> g;
vector<int> used;
 
vector<int> order;
void dfs(int v) {
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    order.push_back(v);
}
 
int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    used.resize(n + 1);
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i);
    reverse(order.begin(), order.end());

    ///check if good
    ///assign numbers according to order ---> check each edge
    vector<int> id(n + 1);
    for (int i = 0; i < n; i++) {
        id[order[i]] = i + 1;
    }
    for (int v = 1; v <= n; v++) {
        for (int u : g[v]) {
            if (id[v] > id[u]) {
                cout << "NO TOP SORT";
                return 0;
            }
        }
        
    }
    return 0;
}