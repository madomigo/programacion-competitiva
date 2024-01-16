#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
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

    //for (int i = 0; i < n; i++) cout << sol[i] << ' ';
    //cout << '\n';

    int cuenta = ans;
    int imprime[ans + 1];
    for (int i = n - 1; i >= 0; i--) {
        if (sol[i] == cuenta) {
            imprime[sol[i]] = i + 1;
            cuenta--;
        }
    }

    for (int i = 1; i < ans; i++) {
        cout << imprime[i] << " ";
    }
    cout << imprime[ans] << "\n";

}
