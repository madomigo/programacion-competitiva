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
    int end;
    for (int i = 0; i < n; i++) {
        if (sol[i] > ans) {
            ans = sol[i];
            end = i;
        }
    }

    int from;
    for (int i = 0; i < end; i++) {
        if (sol[i] == 1) from = i;
    }

    cout << ans << endl;
    int cuenta = 1;
    for (int i = from; i <= end; i++) {
        if (sol[i] == cuenta) {
            cout << i + 1 << " ";
            cuenta++;
        }
    }
}
