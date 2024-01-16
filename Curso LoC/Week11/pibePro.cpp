#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> opt;
vector<int> w;
vector<int> ans;
 
///it finds the answer for dp[i][j]
void find_answer(int i, int j) {
    if (i == -1)
        return;
    if (opt[i][j] == 0) {
        find_answer(i, j - 1);
        return;
    } else if (opt[i][j] == 1) {
        find_answer(i - 1, j);
        return;
    } else {
        find_answer(i - 1, j - w[i]);
        //cout << "WE TAKE ITEM " << i << endl;
        ans.push_back(i);
        return;
    }
}
 
int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> c(n);
    w.resize(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> c[i];
    vector<vector<int>> dp(n, vector<int>(W + 1));
    opt.resize(n, vector<int>(W + 1));
    ///j = 0...W, dp[n - 1][W]
    ///initial values
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
        opt[i][0] = 1;
    }
    for (int j = 0; j <= W; j++)
        if (j >= w[0]) {
            dp[0][j] = c[0];
            opt[0][j] = 2;
        }
        else {
            dp[0][j] = 0;
            opt[0][j] = 1;
        }
 
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= W; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (w[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
 
 
            if (dp[i][j] == dp[i][j - 1])
                opt[i][j] = 0;
            else if (dp[i][j] == dp[i - 1][j])
                opt[i][j] = 1;
            else
                opt[i][j] = 2;
        }
    find_answer(n - 1, W);
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << ' ';
    return 0;
}