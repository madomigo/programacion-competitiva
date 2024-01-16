#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int n, k;
vector<int> planks;
 
bool check (int x) {
    if (x == 0) return true;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        count += planks[i] / x;
        if (count >= k) break;
        if (planks[i] / x == 0) break;
    }
 
    return (count >= k);
}

 
int32_t main () {
    cin >> n >> k;
    planks.clear();
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        planks.push_back(num);
    }
 
    sort(planks.begin(), planks.end());
 
    int low = 0, high = 1000000001, mid;
    int min = 0;
    while (low <= high) {
        mid = (high + low) / 2;
 
        if (check(mid) == true) {
            min = max(mid, min);
            low = mid + 1;
        }
        else high = mid - 1;
    }
 
    cout << min << "\n";
}