#include <bits/stdc++.h>
using namespace std;

// #define int long long
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
// const int INF = 1e18;
const char nl = '\n';

bool run_case () {
    int c, m, n;
    if (!(cin >> c >> m >> n)) return 0;

    bool tropiezo = 0;

    vi v(n);

    int last;
    cin >> last;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        v[i] = x - last;
        last = x;
    }

    // for (int x : v) cout << x << " ";
    // cout << '\n';

    for (int i = 1; i < n && !tropiezo; i++) {
        if (abs(v[i] - v[i - 1]) > c) tropiezo = 1;
    }

    sort(v.begin(), v.end());

    if (v[n - 1] - v[0] > m) tropiezo = 1;

    if (tropiezo) cout << "Tropiezo" << endl;
    else cout << "Ok" << endl;
    return 1;
}

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    while (run_case());
}