#include <iostream>
#include <vector>
using namespace std;
 
 
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n), dp(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = 1; ///there is no previous element, take element i only
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) { //because we want an increasing subsequence
                //we can take j as a previous element
                dp[i] = max(dp[i], dp[j] + 1);
            }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}