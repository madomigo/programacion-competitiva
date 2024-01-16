#include <bits\stdc++.h>
using namespace std;
#define int long long

vector<set<int>> graph;
vector<bool> visited;

void dfs (int x) {
    visited[x] = 1;

    for (auto i : graph[x]){
        if (visited[i] == 0) {
            dfs (i);
        }
    }
}

int32_t main () {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> price (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> price[i].first;
        price[i].second = i;
    }

    sort(price.begin() + 1, price.end());

    graph.resize(n + 1);
    visited.resize(n + 1);

    int n1, n2;
    while (m--) {
        cin >> n1 >> n2;

        graph[n1].insert(n2);
        graph[n2].insert(n1);
    }

    for (int i = 1; i <= n; i++) visited[i] = 0;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[price[i].second]) {
            sum += price[i].first;

            dfs(price[i].second);
        }
    }

    cout << sum << '\n';

}