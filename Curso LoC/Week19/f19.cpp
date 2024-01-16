#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;           
    string s;
    cin >> s;

    int L = count(s.begin(), s.end(), 'L');
    int ans = 0;
    for (int i = 0; i < L; i++) {
        if (s[i] == 'R') ans++;
    }
    cout << ans << '\n';
}