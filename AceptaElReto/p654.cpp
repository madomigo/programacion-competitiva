#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main () {
    int t;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> m >> n;
        vector<vector<char>> v (n, vector<char> (m));
        set<char> s;
        map<char, pair<pair<int, int>, pair<int,int>>> map; // {{izq, der}, {arr, abajo}}
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (v[i][j] == '.') continue;
                s.insert(v[i][j]);
                map[v[i][j]].first.first = j;
                map[v[i][j]].first.second = j;
                map[v[i][j]].second.first = i;
                map[v[i][j]].second.second = i;

            }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '.') continue;
                map[v[i][j]].first.first = min(map[v[i][j]].first.first, j);
                map[v[i][j]].first.second = max(map[v[i][j]].first.second, j);
                map[v[i][j]].second.first = min(map[v[i][j]].second.first, i);
                map[v[i][j]].second.second = max(map[v[i][j]].second.second, i);
                //cout << i << ' ' << j << ' ' << v[i][j] << ": " << map[v[i][j]].first.first << '\n';
            }
        }
        vector<char> ans;
        vector<vector<char>> ans2;
        int cnt = 0;
        bool posible = true;
        while (ans.size() != s.size()) {
            vector<char> sol;
            for (auto x : s) {
                if (count(ans.begin(), ans.end(), x)) continue;
                bool full = true;
                for (int i = map[x].second.first; i <= map[x].second.second; i++) {
                    if (!full) break;
                    for (int j = map[x].first.first; j <= map[x].first.second; j++) {
                        if (v[i][j] != '.' && v[i][j] != x) {
                            full = 0;
                            break;
                        }
                    }
                }

                if (full) {
                    sol.push_back(x);
                    ans.push_back(x);
                }
            }

            for (auto x : sol) {
                for (int i = map[x].second.first; i <= map[x].second.second; i++) {
                    for (int j = map[x].first.first; j <= map[x].first.second; j++) {
                        v[i][j] = '.';
                    }
                }
            }
            
            //cout << map['Z'].first.first  << ' ' << map['Z'].first.second << ' ' << map['Z'].second.first << ' ' << map['Z'].second.second << '\n';
            if (sol.size() == 0) {
                posible = false;
                cout << "IMPOSIBLE\n";
                cout << "----\n";
                break;
            }
            sort(sol.begin(), sol.end());
            ans2.push_back(sol);
        }

        if (!posible) continue;

        for (int i = 0; i < ans2.size(); i++) {
            cout << ans2[i][0];
            for (int j = 1; j < ans2[i].size(); j++)
                cout << ' ' << ans2[i][j];
            cout << '\n';
        }
        cout << "----\n";
    }
}