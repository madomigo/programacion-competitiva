#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int f, a, c;

    while (cin >> f >> a >> c) {
        priority_queue<int> q;

        int asientos;
        for (int i = 0; i < f; i++) {
            cin >> asientos;
            q.push(-asientos);
        }


        int mejorFila;
        int ans = 0;
        while (c > 0) {
            mejorFila = -q.top();
            q.pop();
            if (mejorFila == a) {
                break;
            }
            ans += (a-mejorFila);
            mejorFila++;
            q.push(-mejorFila);
            c--;
        }

        cout << ans << '\n';

    }
}