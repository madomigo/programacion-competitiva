/*
    Autor: Mateo Dominguez Gomez
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int MOD = 1000000007;
const int mod = 998244353;
const int INF = 1e18;
const char nl = '\n';

vector<int> precio;
vector<set<pair<int,int>>> g; // {ciudad, distancia}
vector<int> pasosACiud;
vector<vector<int>> visited; // En cada ciudad guardo para cada gasolina la vez mas barata que he llegado (la primera)



void run_case (int n, int m) {
    int c, s, e;
    cin >> c >> s >> e;
    s--; // para empezar en 0
    e--;

    // Calculemos ahora el dinero gastado
    bool llega = false;
    priority_queue<pair<int ,pair<int,int>>> q; // {Dinero gastado , {gasolina, ciudad}}
    q.push({0, {0, s}});
    visited.assign(n, vector<int> (c+1, -1));

    int dinero, gasolina,ciudad;
    while (!q.empty()) {
        dinero = -q.top().first;
        gasolina = -q.top().second.first;
        ciudad = q.top().second.second;
        q.pop();


        if (visited[ciudad][gasolina] != -1)
            continue;


        if (ciudad == e) {
            llega=true;
            break;
        }

        visited[ciudad][gasolina] = dinero;


        if (gasolina < c) {
            q.push({-(dinero + precio[ciudad]), {-(gasolina+1), ciudad}});
        }
        for (auto i : g[ciudad]) {
            if (gasolina >= i.second) {
                q.push({-dinero, {-(gasolina - i.second), i.first}});
            }
        }
    }


    if (llega) {
        cout << dinero << nl;
    }
    else {
        cout << "IMPOSIBLE" << nl;
    }
}

int32_t main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    while (cin >> n >> m) {
        precio.clear();
        precio.resize(n);
        for (int i = 0; i < n; i++)
            cin >> precio[i];

        g.clear();
        g.resize(n);

        int u,v,d;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> d;
            u--;
            v--;
            g[u].insert({v,d});
            g[v].insert({u,d});
        }

        int q;
        cin >> q;

        while (q--)
            run_case(n,m);

        cout << "---" << nl;
    }
        
}