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

void run_case (int n, int l) {
    vector<int> v(n);

    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    int nMx = 0;
    int sum = 0;
    int bestSum;
    int pgInicial = 0;
    for (int i = 0; i < l; i++) {
        if (v[i] == mx) {
            nMx++;
        }
        sum += v[i];
    }
    
    if (nMx > 0) {
        bestSum = sum;
    }
    else 
        bestSum = 0;

    for (int i = l; i < n; i++) {
        sum -= v[i-l];
        sum += v[i];
        if (v[i-l] == mx) {
            nMx--;
        }

        if (v[i] == mx) {
            nMx++;
        }

        if (nMx > 0 && sum >= bestSum) {
            bestSum = sum;
            pgInicial = i-l+1;
        }
    }

    cout << pgInicial + 1 << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,l;
    while (true) {
        cin >> n >> l;
        if (n == 0 && l == 0)
            return 0;
        run_case(n,l);

    }
}