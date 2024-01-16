#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b;
    while (cin >> a >> b) {
        map<int,int> m;
        int cnt = 3;
        string ans = "0.";
        a *= 10;
        m[a] = 2;
        int p = -1;
        int div;
        while (a % b != 0) {
            div = a / b;
            a %= b;
            a *= 10;
            ans += to_string(div);
            if (m.find(a) != m.end()) {
                p = m[a];
                break;
            }
            m[a] = cnt;
            cnt++;
        }
        if (a % b == 0) ans += to_string(a / b);
        if (p == -1) cout << ans << '\n';
        else {
            for (int i = 0; i < ans.size(); i++) {
                if (i == p) {
                    cout << '|';
                }
                cout << ans[i];

            }
            cout << '|' << '\n';
        }
    }
}