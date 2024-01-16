#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int ans = INT32_MAX;

    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] < ans) ans = nums[i] - nums[i - 1];
    }
    cout << ans << "\n";
}