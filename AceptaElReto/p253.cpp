#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
const int INF = INT32_MAX;

int main () {
    int n, k, s, e;
    while (true) {
        cin >> n >> k >> s >> e;
        if (n == 0 && k == 0 && s == 0 && e == 0) break;

        unordered_map<int,int> atajos;
        
        int a, b;
        for (int i = 0; i < s + e; i++) {
            cin >> a >> b;
            atajos[a] = b;
        }

        vector<bool> visited (n * n + 1, false);
        priority_queue<pair<int, int>> q;
        q.push({-0,1});
        
        int pasos, casilla;
        while (!q.empty()) {
            pasos = -q.top().first;
            casilla = q.top().second;
            q.pop();

            if (casilla > n * n) continue;
            if (casilla == n*n) break;

            for (int i = 1; i <= k; i++) {
                if (casilla + i > n * n) break;
                if (visited[casilla + i] == true) continue;
                
                if (atajos[casilla + i] == 0) {
                    q.push({-(pasos + 1), casilla + i});
                    visited[casilla + i] = true;
                }
                else if (visited[atajos[casilla + i]] == false) {
                    q.push({-(pasos + 1), atajos[casilla + i]});
                    visited[atajos[casilla + i]] = true;
                }
            }
            
        }

        cout << pasos << '\n';

    }

}