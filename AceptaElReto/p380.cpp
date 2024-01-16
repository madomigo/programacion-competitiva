#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while(true) {
        cin >> n;
        if (n == 0) break;
        int ans = 0;
        int c;
        for (int i = 0; i < n; i++) {
            cin >> c;
            ans += c;
        }
        cout << ans << '\n';
    }
}