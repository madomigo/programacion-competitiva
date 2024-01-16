#include <bits/stdc++.h>
using namespace std;

int main () {
    int h, m, h2, m2, n, ans;
    while (true) {
        cin >> h; getchar(); cin >> m; cin >> h2; getchar(); cin >> m2; cin >> n;
        if (h == 24) break;
        ans = 0;
        while (h <= h2 && !(h == h2 && m > m2)) {
            if (h / 10 == n || h % 10 == n || m / 10 == n || m % 10 == n) ans++;
            m++;
            if (m == 60) {
                m = 0;
                h++;
            }
        }
        cout << ans << '\n';
    }
}