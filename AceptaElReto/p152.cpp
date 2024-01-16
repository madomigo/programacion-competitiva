#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        map<int, int> m;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            m[num]++;
        }

        int mx = 0;
        int ans;
        for (auto i : m) {
            if (i.second > mx) {
                ans = i.first;
                mx = i.second;
            }
        }
        cout << ans << '\n';
    }
}