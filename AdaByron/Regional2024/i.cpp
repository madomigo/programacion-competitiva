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


vector<int> v;
bool puede(int p, int n, int mxViajes)  {
    int pesoViaje = 0;
    int nViajes = 0;
    for (int i = 0; i < n; i++) {
        if (pesoViaje + v[i] > p) {
            nViajes++;
            pesoViaje = v[i];
        }
        else {
            pesoViaje += v[i];
        }
    }

    if (pesoViaje > 0) nViajes++;

    return nViajes <= mxViajes;
}

void run_case (int n, int t) {
    v.clear();
    v.resize(n);
    
    int mx = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        sum += v[i];
    }

    int l = mx, r = sum;
    int m;
    int ans = sum;
    while (l < r) {
        m = (l+r)/2;
        if (puede(m, n, t)) {
            r = m;
            ans = min(ans, m);
        } else {
            l = m+1;
        }
    }

    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, t;
    
    while (t) {
        cin >> n >> t;
        if (n == 0 && t == 0) {
            return 0;
        }
        run_case(n,t);
    }
}