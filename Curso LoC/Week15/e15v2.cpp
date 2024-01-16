#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    int n,a,b,x,ans;
    string s;
    while (t--) {
        x = -1;
        ans = 0;
        cin >> n >> a >> b >> s; 
        for (int i = 0; i < n; i++) 
            if (s[i] == '1') {
                if (x == -1)
                    ans += (i + 1) * a + i * b;
                else ans += min((i - x) * (a + b*2), (i - x + 2) * a + (i - x + 2) * b);
                x = i;
            }
        if (x > -1) ans += a*2+b*4+(n-x-1)*(a+b);
        else ans += n*a+(n+1)*b;
        cout << ans << '\n';
    }
}