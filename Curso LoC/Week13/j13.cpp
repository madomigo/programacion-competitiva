#include <bits/stdc++.h>
using namespace std;
#define int long long

 
int32_t main () {
    int n, m, k;
    cin >> n >> m >> k;
    getchar();
 
    vector<vector<char>> museum (n + 1, vector<char> (m + 1));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            museum[i][j] = getchar();
        }
        getchar();
    }

    queue<pair<int,int>> q;
    int x, y;
 
    vector<vector<bool>> visited (n + 1, vector<bool> (m + 1));
    vector<vector<int>> cost (n + 1, vector<int> (m + 1));
    for (int i = 0; i < k; i++) {
        cin >> x >> y; 

        if (visited[x][y]) {
            cout << cost[x][y] << '\n';
            continue;
        }
        q.push({x, y});
        int pics = 0;

        vector<pair<int,int>> same;

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (visited[x][y]) continue;
            
            same.push_back({x, y});
 
            visited[x][y] = true;
 
            
            if (x > 1 && museum[x - 1][y] != '*') q.push({x - 1, y});
            if (x < n && museum[x + 1][y] != '*') q.push({x + 1, y});
            if (y > 1 && museum[x][y - 1] != '*') q.push({x, y - 1});
            if (y < m && museum[x][y + 1] != '*') q.push({x, y + 1});

            if (x > 1 && museum[x - 1][y] == '*') pics++;
            if (x < n && museum[x + 1][y] == '*') pics++;
            if (y > 1 && museum[x][y - 1] == '*') pics++;
            if (y < m && museum[x][y + 1] == '*') pics++;
 
        }

        for (auto el : same) {
            cost[el.first][el.second] = pics;
        }
        cout << pics << '\n';
 
    }
    
}