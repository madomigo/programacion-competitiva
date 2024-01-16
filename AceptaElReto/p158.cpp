#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arriba = 0;
        int abajo = 0;
        int p, num;
        cin >> p;
        for (int i = 1; i < n; i++) {
            cin >> num;
            if (p > num) abajo++;
            else if (p < num) arriba++;
            p = num;
        }
        cout << arriba << ' ' << abajo << '\n';
    }
}