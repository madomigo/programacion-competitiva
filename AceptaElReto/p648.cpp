#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
vector<int> v;
vector<pair<int,int>> dp;

int main () {
    int w, n;
    while (cin >> w >> n) {
        v.resize(n + 1);
        dp.assign(w + 1, {0, -1});
        for (int i = 0; i < n; i++) 
            cin >> v[i];
        dp[0] = {0, 0};
        for (int i = 1; i <= w; i++) {
            //cout << i << ' ';
            for (int j = 0; j < n; j++) {
                if (i - v[j] < 0) break;

                if (dp[i - v[j]].second != -1 && (dp[i].second == -1 || dp[i].second > dp[i - v[j]].second + 1)) {
                    dp[i].second = dp[i - v[j]].second + 1;
                    dp[i].first = v[j];
                }

                else if (dp[i - v[j]].second != -1 && dp[i].second == dp[i - v[j]].second + 1 && dp[i].first < v[j]) {
                    dp[i].second = dp[i - v[j]].second + 1;
                    dp[i].first = v[j];
                }

            }
        }

        //for (int i = 0; i <= w; i++)
            //cout << i << ": " << dp[i].first << ' ' << dp[i].second << '\n';

        if (dp[w].second == -1) cout << "Imposible\n";
        else {
            cout << dp[w].second << ":";
            int i = w;
            vector<int> ans;
            while (i != 0) {
                ans.push_back(dp[i].first);
                i -= dp[i].first;
            }
            sort(ans.begin(), ans.end());
            reverse(ans.begin(), ans.end());
            for (auto i : ans)
                cout << ' ' << i;
            cout << '\n';
        }
    }
   
}