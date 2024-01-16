#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a < b && a < c) cout << max(b, c) - a << '\n';
        else if (a > b && a > c) cout << a - min(b, c) << '\n';
        else cout << max(b, c) - min(b, c) + min(a - min(b, c), max(b, c) - a) << '\n';
    }
}