#include <bits/stdc++.h>
using namespace std;

vector<set<int>> g (1001);
vector<bool> visited(1001);
using namespace std;

//KNAPSACK
int maxSum(vector<pair<int, int>>& pairs, int A) {
    int n = pairs.size();
    vector<vector<int>> dp(n + 1, vector<int>(A + 1, 0));

    for (int i = 1; i <= n; i++) {
        int val1 = pairs[i - 1].first;
        int val2 = pairs[i - 1].second;

        for (int j = 0; j <= A; j++) {
            if (val1 <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - val1] + val1);
            if (val2 <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - val2] + val2);

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    return dp[n][A];
}

//{amigos, enemigos}
pair<int,int> BFS (int i, bool amigos) {
    visited[i] = true;
    int namigos = amigos, nenemigos = !amigos;
    pair<int,int> conexos;
    pair<int, int> total = {0,0};
    for (int j : g[i]) {
        if (!visited[j]) {
            conexos = BFS(j, !amigos);
            total.first += conexos.first;
            total.second += conexos.second;
        }
    }

    return {namigos + total.first, nenemigos + total.second};
}

int main () {
    int N,P,A;

    while(cin >> N >> P >> A) {
        for (int i = 0; i <= 1000; i++) {
            visited[i] = 0;
            g[i].clear();
        }
        int a, b;
        for (int i = 0; i < P; i++) {
            cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }

        int ans = 0;
        pair<int,int> prov;

        vector<pair<int,int>> posibles;

        for (int i = 1; i <= N; i++) {
            if (visited[i]) 
                continue;

            prov = BFS(i, 1);
            posibles.push_back(prov);

        }
        
        cout << maxSum(posibles, A) << '\n';
        
    } 
}