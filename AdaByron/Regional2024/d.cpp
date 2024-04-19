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

int getPos(int i, int j,int m) {
    int mn = min(i,j);
    i-=mn;
    j-=mn;

    if (i == 0) {
        return j;
    }
    return m + i - 1;
}

void run_case(int n, int m, int v) {
    vector<int> vec (n+m-1, v);
    string op;
    cin >> op;
    int i,j,w;
    while (op != "FIN") {
        if (op == "set") {
            cin >> i >> j >> w;
                vec[getPos(i,j,m)] = w;
        }

        if (op == "get") {
            cin >> i >> j;
            cout << vec[getPos(i,j,m)] << nl;
        }

        cin >> op;
    }

    cout << "---" << nl;

}

int32_t main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, v;
    while (true) {
        cin >> n >> m >> v;
        if (n == 0 && m == 0 && v == 0)
            return 0;
        run_case(n, m, v);
    }
}
