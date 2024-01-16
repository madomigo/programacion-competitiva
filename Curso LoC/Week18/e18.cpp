#include <bits/stdc++.h>
using namespace std;
#define int long long

int divisores(int n) {
    set<int> s;
    for (int a = 1; a * a <= n; a++)
        if (n % a == 0) {
            s.insert(a);
            s.insert(n / a);
        }
    return s.size();
}

int32_t main () {
    int q;
    cin >> q;
    int n;
    while (q--) {
        cin >> n; 
        vector<int> v (n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int num = v[0] * v[n - 1];
        if (divisores(num) - 2 != n) {
            cout << "-1\n";
            continue;
        }
        bool is = true;
        for (int i = 1; i <= (n - 1) / 2; i++) {
            if (num != v[i] * v[n - 1 - i]) {
                is = false;
                break;
            }
        }
        if (is) cout << num << '\n';
        else cout << "-1\n";
    }
}
/*
1
2
4 3
12
*/