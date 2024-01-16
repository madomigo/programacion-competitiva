#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort (a, a + n);

    while (q--) {
        int num;
        cin >> num;

        long long mnDif = INT32_MAX;
        long long mn = INT32_MAX;

        long long l = 0, r = n;
        while (l <= r) {
            long long mid = (l + r) / 2;

            long long dif = abs(a[mid] - num);

            if (dif < mnDif) {
                mnDif = dif;
                mn = a[mid];
            }
            else if (dif == mnDif && a[mid] < mn) mn = a[mid];

            if (a[mid] > num) {
                r = mid - 1;
            }
            else l = mid + 1;
        }

        cout << mn << '\n';
    }
}