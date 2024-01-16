#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int n;
    cin >> n;
    int ans = 0;
    int x, y;
    cin >> x >> y;
    int x0 = x, y0 = y;
    n--;
    int x1, y1;
    while (n--) {
        cin >> x1 >> y1;
        ans += __gcd(abs(x - x1), abs(y - y1));
        x = x1, y = y1;
    }
    ans += __gcd(abs(x0 - x), abs(y0 - y));
    cout << ans << '\n';
}