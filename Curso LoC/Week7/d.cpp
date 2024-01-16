#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 1, r = n;
    int mn = INT32_MAX;
    while (l <= r) {
        int mid = (l + r) / 2;

        int res = mid;
        int dividing = 1;
        while (dividing++ < mid) res += mid / dividing;


        if (res >= n) {
            r = mid - 1;
            mn = min (mn, mid);
        }
        else l = mid + 1;
    }

    cout << mn << '\n';


}