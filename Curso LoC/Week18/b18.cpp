#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int exp(int a, int b) {
    if (b == 0) return 1 % MOD;
    if (b % 2 == 1) return exp(a, b - 1) * a % MOD;
    else {
        int ak = exp(a, b/2);
        return ak * ak % MOD;
    }
}

int32_t main () {
    int t;
    cin >> t;
    int factorial[1000000];
    factorial[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
}
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n - k < 0) {
            cout << 0 << '\n';
            continue;
        }
        int a = factorial[n];
        a %= MOD;
        int b = factorial[k] * factorial[n - k];
        b%=MOD;
        cout << a * exp(b, MOD - 2) % MOD << '\n';
    }
}