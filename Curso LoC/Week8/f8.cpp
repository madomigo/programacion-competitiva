#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int n, q;

    cin >> n >> q;

    vector<int> v;
    int sum = 0;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        v.push_back(sum + num);
        sum += num;
    }

    int x;
    while (q--) {
        cin >> x;

        int low = 0, high = n - 1, mid;
        bool found = false;
        int good = 0;
        while (low <= high && !found) {

            mid = (high + low) / 2;

            if (x == v[mid]) {
                found = true;
                good = mid;

            }
            else if (x < v[mid]) {
                high = mid - 1;
                good = mid;
            }
            else low = mid + 1;
        }

        cout << good + 1 << '\n';
    }
}