#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, c;
    while(cin >> n >> c) {
        priority_queue<pair<int,int>> q; // {time, index};
        for (int i = 1; i <= n; i++) {
            q.push({0, -i});
        }
        int time;
        pair<int,int> caja;
        for (int i = 0; i < c; i++) {
            cin >> time;
            caja = q.top();
            q.pop();
            caja.first -= time;
            q.push(caja);
        }

        caja = q.top();
        cout << -caja.second << '\n';
    }
}