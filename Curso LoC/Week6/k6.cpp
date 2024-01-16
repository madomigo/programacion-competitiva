#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {
    int n;
    cin >> n;

    int nums[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    sort(nums + 1, nums + 1 + n);

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += abs(nums[i] - i);
    }
    cout << ans << "\n";

}