#include <bits/stdc++.h>
using namespace std;

const string c = "stanlee";

int main () {
    int t;
    cin >> t;
    getchar();
    string s;
    while (t--) {
        getline(cin, s);
        int pos = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < 'A' || s[i] > 'z' || (s[i] > 'Z' && s[i] < 'a')) continue;
            else if (s[i] <= 'Z') s[i] += 32;

            if (s[i] == c[pos]) {
                pos++;
                if (pos > 6) {
                    ans++;
                    pos = 0;
                }
            }
        }
        cout << ans << '\n';    
    }
}