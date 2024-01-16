#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<pair<int,int>> v (n);
        int a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v[i] = {-a, b};
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            cout << -v[i].first << ' ' << v[i].second << '\n';
        }
        cout << "---\n";
    }
}