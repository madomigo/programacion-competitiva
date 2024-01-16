#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    int c, a;
    int f, i;
    while (t--) {
        cin >> c >> a;
        c--;
        if (a % c == 0) {
            a += a / c;
            cout << a - 1 << ' ' << a << '\n';
        }
        else {
            a += a / c;
            cout << a << ' ' << a << '\n';
        }
    }
}