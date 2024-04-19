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

void run_case (int n) {
    vector<int> v (n);
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sorted[i] = v[i];
    }

    sort(sorted.begin(), sorted.begin() + n);


    bool isSorted = true;
    int l = -1;
    while (l < n-1 && isSorted) {
        l++;
        if (v[l] != sorted[l]) {
            isSorted = false;
            break;
        }
    }


    if (isSorted) {
        cout << 0 << nl;
        return;
    }

    isSorted = true;
    int r = n;
    while (n > 0) {
        r--;
        if (v[r] != sorted[r]) {
            isSorted = false;
            break;
        }
    }

    cout << r - l + 1<< nl;


}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;
    
    // cin >> t;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            return 0;
        
        run_case(M);

    }
}