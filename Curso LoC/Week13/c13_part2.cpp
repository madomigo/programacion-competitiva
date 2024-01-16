#include <bits/stdc++.h>
using namespace std;

vector<set<int>> graph;
vector<int> p, cycle;
vector<int> visited;
int n, m;


void dfs (int x, int parent) {
    //cout << "Empiezo: " << x << '\n';
    visited[x] = 1;
    p[x] = parent;

    for (auto i : graph[x]){
        //cout << x << " conecta: " << i << '\n';
        
        
        if (visited[i] == 0) {
            dfs (i, x);
        }

        else {
            if (visited[i] == 1 && cycle.size() == 0) {
                int xi = x;
                while (x != i) {
                    cycle.push_back(x);
                    x = p[x];   
                }
                cycle.push_back(x);
                
                x = xi;
                cycle.push_back(x);
                
            }
            
        }
    }
    visited[x] = 2;
    //cout << "Salgo de: " << x << '\n';
    return;
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        graph.resize(n + 1);
        graph.clear();
        visited.resize(n + 1);
        p.resize(n + 1);
        p.clear();
        cycle.clear();

        int fr, to;
        while (m--) {
            cin >> fr >> to;

            graph[fr].insert(to);

        }

        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
        }


        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0){
                dfs(i, -1);
            }
        }

        if (cycle.size() == 0) {
            cout << "YES\n";
        }

        else {
            cout << "NO\n";

            cout << cycle.size() - 1 << '\n';
            reverse(cycle.begin(), cycle.end());
            for (auto i : cycle) cout << i << " ";
            cout << '\n';
        }
    }
}