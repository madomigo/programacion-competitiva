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

void run_case (int n, int c, int a, int l, int t) {
    vector<set<int>> v (n+1);
    vector<int> alex (n+1,INF);
    vector<int> lucas (n+1,INF);
    vector<int> trabajo (n+1, INF);

    int o, d;
    for (int i = 0; i < c; i++) {
        cin >> o >> d;
        v[o].insert(d);
        v[d].insert(o);
    }

    priority_queue<pair<int,int>> q;
    q.push({0, a});

    int punto, distancia;
    while (!q.empty()) {
        punto = q.top().second;
        distancia = -q.top().first;
        q.pop();

        if (alex[punto] != INF) {
            continue;
        }

        alex[punto] = distancia;

        for (auto i : v[punto]) {
            if (alex[i] == INF) {
                q.push({-(distancia + 1), i});
            }
        }
    }


    q;
    q.push({0, l});

    while (!q.empty()) {
        punto = q.top().second;
        distancia = -q.top().first;
        q.pop();

        if (lucas[punto] != INF) {
            continue;
        }

        lucas[punto] = distancia;

        for (auto i : v[punto]) {
            if (lucas[i] == INF) {
                q.push({-(distancia + 1), i});
            }
        }
    }

    q;
    q.push({0, t});

    while (!q.empty()) {
        punto = q.top().second;
        distancia = -q.top().first;
        q.pop();

        if (trabajo[punto] != INF) {
            continue;
        }

        trabajo[punto] = distancia;

        for (auto i : v[punto]) {
            if (trabajo[i] == INF) {
                q.push({-(distancia + 1), i});
            }
        }
    }

    int mn = n + 2;
    for (int i = 1 ; i <= n; i++) {
        mn = min(mn, alex[i] + lucas[i] + trabajo[i]);
    }

    cout << mn << nl;
    
}

int32_t main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, c, a, l, t;
    while (cin >> n >> c >> a >> l >> t) {
        run_case(n,c,a,l,t);
    }
}