#include <bits/stdc++.h>
using namespace std;

int main () {
    int l, r, n;
    while (true) {
        cin >> l >> r >> n;
        if (l == 0 && r == 0 && n == 0) break;
        int k;
        cin >> k;
        int x;
        while (k--) {
            cin >> x;
            if (n < x) r = min(x - 1, r);
            else l = max(l, x);
        }
        //cout << l << ' ' << r << '\n';
        if (r == l) cout << "LO SABE\n";
        else cout << "NO LO SABE\n";
    }

}