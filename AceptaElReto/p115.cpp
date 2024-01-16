#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int n, l, r, d, sum;
    while (true) {
        cin >> n;
        if (n == 0) break;
        d = 1;
        l = n * n;
        r = 0;
        bool kap = false;
        while (l > 0) {
            r += ((l % 10) * d);
            l /= 10;
            d *= 10;
            sum = l + r;
            if (r > 0 && sum == n) {
                kap = true;
                break;
            }

        }

        if (kap) cout << "SI\n";
        else cout << "NO\n";

    }
}

