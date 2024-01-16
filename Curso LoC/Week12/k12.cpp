#include <bits/stdc++.h>
using namespace std;


 
int main () {
    int n, m;
    cin >> n >> m;
    getchar();
 
    vector<vector<char>> lab (n + 1, vector<char> (m + 1));
    vector<pair<int, int>> hunters;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            lab[i][j] = getchar();
            if (lab[i][j] == 'H') {
                hunters.push_back({i, j});
            }
        }
        getchar();
    }
 
 
    queue<pair<int,int>> q;
    int x, y;
 
    vector<pair<pair<int,int>, int>> ans;
    vector<vector<bool>> visited (n + 1, vector<bool> (m + 1));
    for (auto h : hunters) {
        vector<pair<int, int>> same;
 
        q.push({h.first, h.second});
        int treasures = 0;

        int posx, posy;
        posx = h.first;
        posy = h.second;


        //cout << "hunter: " << posx << ' ' << posy << '\n';

        if (visited[posx][posy]) continue;

 
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (visited[x][y]) continue;
 
            visited[x][y] = true;
 
            if (lab[x][y] == 'T') {
                treasures++;
            }

            if (lab[x][y] == 'H') {
                same.push_back({x, y});
                //cout << "junto: " << x << ' ' << y << ' ' << "con: " << posx << ' ' << posy << '\n';
            }
            
            if (x > 1 && lab[x - 1][y] != '#') q.push({x - 1, y});
            if (x < n && lab[x + 1][y] != '#') q.push({x + 1, y});
            if (y > 1 && lab[x][y - 1] != '#') q.push({x, y - 1});
            if (y < m && lab[x][y + 1] != '#') q.push({x, y + 1});
 
        }

        for (auto el : same) {
            ans.push_back({{el.first, el.second}, treasures});
        }

 
    }
    
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i.second << ' ';
 
    cout << '\n';
}