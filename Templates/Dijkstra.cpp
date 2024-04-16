#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<set<pair<int,int>>> g (10001);
int N;

int dijkstra (int a, int b) {
    int v,w;
    priority_queue<pair<int,int>> q;
    vector<int> coste (N+1,-1);
    q.push({0,a});
    while (!q.empty()) {
        w = -q.top().first;
        v = q.top().second;
        q.pop();

        if (coste[v] != -1)
            continue;

        coste[v] = w;

        if (v == b)
            break;

        for (auto i : g[v]) {
            q.push({-(w+i.second),i.first});
        }

    }
    return coste[b];
}
