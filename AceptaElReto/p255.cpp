#include <bits/stdc++.h>
using namespace std;

string s;

int Palindrome(int from, int to) {
    int l = from, r = to;
    while (l <= r) {
        if (s[l] != s[r]) return 0;
        l++, r--;
    }

    return (to - from + 1);
}

int main () {
    while (cin >> s) {
        int ans = 1;
        int p = s.length() - 1;
        
        for (int i  = 0; i < s.length() && ans <= (p - i); i++) {
            while ((p - i) >= ans) {
                if (s[i] == s[p]) ans = max(ans, Palindrome(i, p));
                p--;
            }
            p = s.length() - 1;
        }   

        cout << ans << '\n';
    }
}