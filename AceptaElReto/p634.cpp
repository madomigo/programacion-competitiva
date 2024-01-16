#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O') cnt++;
            else cnt = 0;
            ans += cnt * 10;
        }
        cout << ans << '\n';
    }
}