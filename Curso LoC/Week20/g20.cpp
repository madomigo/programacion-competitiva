#include <bits/stdc++.h>
using namespace std;
int main () {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << 0 << '\n';
        return 0;
    }   
    int n = y / x, ans = 0;
    int p;
    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0)
            continue;
        if (__gcd(i, n / i) > 1) 
            continue;
        if (x * i >= l && x * n / i <= r) {
            if (i * i == n) ans++;
            else ans += 2;
        }
    }
    cout << ans << '\n';
}