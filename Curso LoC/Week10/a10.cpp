#include <iostream>
#include <array>
using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    int sol[n];
    for (int i = 0; i < n; i++) {
        sol[i] = 1;
        cin >> nums[i];
        for (int j = i; j >= 0; j--) {
            if (nums[i] == nums[j] && sol[j] > sol[i]) {
                sol[i] = sol[j];
            }
            else if (nums[i] > nums[j] && sol[j] >= sol[i]) {
                sol[i] = sol[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sol[i] > ans) ans = sol[i];
    }

    cout << ans << endl;
}
