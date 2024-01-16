#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    if (s != s2) {
        cout << "YES\n";
        cout << s2 << '\n';
        return 0;
    }

    int can = -1;
    
    for (int i = 1; i < n; i++) {
        if (s2[i] != s[0]) {
            can = i;
            break;
        }
    }

    if (can != -1) {
        cout << "YES\n";
        cout << s2[can];
        for (int i = 1; i < n; i++) {
            if (i == can) cout << s2[0];
            else cout << s2[i];
        }
        cout << '\n';
    }
    else cout << "NO\n";

}