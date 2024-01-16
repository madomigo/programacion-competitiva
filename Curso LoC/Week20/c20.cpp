#include <bits/stdc++.h>
using namespace std;
 
void factorization(int n) {
    int initial = n;
    vector<pair<int,int>> ans;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            ans.push_back({p, cnt});
        }
    }
    if (n > 1)
        ans.push_back({n, 1});
 
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
}
 
int main () {
    int q;
    cin >> q;
    int n;
    while (q--) {
        cin >> n;
        factorization(n);
    }
}