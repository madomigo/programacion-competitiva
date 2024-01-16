#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int t;
    while (true) {
        cin >> t;
        if (t == 0) break;

        int d, ans = 0;
        while (true) {
            cin >> d;
            if (d == 0) break;

            ans += t * d;
        }

        int h = 0, m = 0, s = 0;

        h = ans / 3600;
        ans %= 3600;

        m = ans / 60;
        ans %= 60;

        s = ans;
        if (h < 10) cout << 0;
        cout << h << ":";
        if (m < 10) cout << 0;
        cout << m << ":";
        if (s < 10) cout << 0;
        cout << s << '\n';
    }

}