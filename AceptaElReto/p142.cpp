#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        queue<int> q, q2, empty;

        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        int last;
        int contador = 0;
        while (q.size() > 1) {
            while (!q.empty()) {
                last = q.front();
                q.pop();
                if (contador != m) {
                    q2.push(last);
                    contador++;
                    
                }
                else 
                    contador = 0;
            }

            q = q2;
            q2 = empty;
        }

        if (q.size() == 1) {
            last = q.front();
            q.pop();
        }
        cout << last << '\n';
    }
}