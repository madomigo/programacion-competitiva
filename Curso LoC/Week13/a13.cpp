#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<set<int>> graph (n + 1);
    int n1, n2;
    for (int i = 0; i < n - 1; i++) {
        cin >> n1 >> n2;
        graph[n1].insert(n2);
        graph[n2].insert(n1);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() == 1) ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';

    cout << '\n';
}