/*
A topological sort is an ordering of the nodes of a directed graph such that if
there is a path from node a to node b, then node a appears before node b in the
ordering.

The idea is to go through the nodes of the graph and always begin a depth-first
search at the current node if it has not been processed yet. During the searches,
the nodes have three possible states:
• state 0: the node has not been processed (white)
• state 1: the node is under processing (light gray)
• state 2: the node has been processed (dark gray)
Initially, the state of each node is 0. When a search reaches a node for the
first time, its state becomes 1. Finally, after all successors of the node have been
processed, its state becomes 2.
If the graph contains a cycle, we will find this out during the search, because
sooner or later we will arrive at a node whose state is 1. In this case, it is not
possible to construct a topological sort.
If the graph does not contain a cycle, we can construct a topological sort by
adding each node to a list when the state of the node becomes 2. This list in
reverse order is a topological sort.

*/

#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

vector<vector<int>> v; // adjacency list
vector<int> state;
bool cycle = false;
vector<int> ans;

void dfs(int i) {
    state[i] = 1;
    for (auto x : v[i]) {
        if (state[x] == 0) dfs(x);
        else if (state[x] == 1) {
            cycle = true;
            return;
        }

    }
    state[i] = 2;
    ans.push_back(i);
}

void run_case () {
    int n, m;
    cin >> n >> m;

    v.clear();v.resize(n+1);
    state.assign(n+1, 0);
    ans.clear();
    cycle = false;

    int a,b;
    for (int i = 0; i < m;  i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    // Topological Sort
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            dfs(i);
        }

        if (cycle) {
            cout << "IMPOSSIBLE" << nl;
            return;
        }
    }


    reverse(ans.begin(), ans.end());

    for (auto i : ans) {
        cout << i << ' ';
    }

    cout << nl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}