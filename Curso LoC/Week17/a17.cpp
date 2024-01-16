#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;


struct Calle {
    int desde, hasta, coste;

    Calle (int d, int h, int c) {
        desde = d;
        hasta = h;
        coste = c;
    }

    bool operator< (const Calle& Calle2) const {
        return (coste > Calle2.coste);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<Calle> q;
    vector<int> dist(n + 1, INF);
    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        q.push(Calle(a,b,c));
    }
    dist[0] = 0;
    Calle calle = Calle(0,0,0);
    while (!q.empty()) {
        calle = q.top();
        q.pop();

        if ()


    }
    
    
    
}