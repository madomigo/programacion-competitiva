#include <bits/stdc++.h>
using namespace std;

const int valor [] = {5, 9, 11, 7, 1, 9, 9, 7, 3, 13, 9, 9, 7,
                     5, 11, 11, 13, 7, 5, 3, 7, 9, 9, 11, 13, 11};

int main () {
    int t;
    cin >> t;
    string s;
    getchar();
    while(t--) {
        getline(cin, s);
        int ans = 0;
        if (s[0] == '!') ans += 19;
        else if (s[0] == '?') ans += 15;
        else {
            ans += valor[s[0] - 65];
        }


        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ' ') {
                ans  += 5;
                continue;
            }
            if (s[i - 1] != ' ') ans += 3;

            if (s[i] == '!') ans += 19;
            else if (s[i] == '?') ans += 15;
            else {
            ans += valor[s[i] - 65];
            }
        }
        cout << ans << '\n';
    }
}