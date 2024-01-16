#include <bits/stdc++.h>    
using namespace std;
#define int long long

int32_t main () {
    int n;
    while(cin >> n) {
        int sum = 0;
        int mx = -1;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            sum += num;
            mx = max(mx, num);
        }

        if (sum - mx >= mx) cout << sum << '\n';
        else cout << 2*mx << '\n';
    }
}