#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    char d;
    while (true) {
        cin >> n >> d;
        if (n == 0 && d == '0') break;
        string ans = "";
        while (n >= 9) {
            ans = to_string(n % 9) + ans;
            n /= 9;
        }
        ans = to_string(n) + ans;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] >= d) cout << (char)(ans[i] + 1);
            else cout << ans[i];
        }
        cout << '\n';
    }
}