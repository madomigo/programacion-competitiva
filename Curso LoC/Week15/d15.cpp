#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<int> v;

bool check(int x) {
    int mov = 0;
    for (int i = n/2; i < n; i++) {
        if (x - v[i] > 0) mov += x - v[i];
        if (mov > k) return 0;
    }
    if (mov > k) return 0;
    return true;
}

int32_t main() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];           
    sort(v.begin(), v.end());

    int low = 1, high = INT32_MAX, mid;
    while(low != high) {
        mid = (low + high + 1) / 2;
        if (check(mid)) low = mid;
        else high = mid - 1;
    }
    cout << low << '\n';
}