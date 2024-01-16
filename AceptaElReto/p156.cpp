#include <bits/stdc++.h>
using namespace std;

int main () {
    int f, t, ans;
    while (true) {
        cin >> f;
        if (f < 0) break;
        ans = 0;
        while (true) {
            cin >> t;
            if (t == -1) break;
            ans = ans + abs(f - t);
            f = t;
        }
        cout << ans << '\n';    
    }

    return 0;
}