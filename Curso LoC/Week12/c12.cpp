#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> v (n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> sources;

    for (int j = 0; j < n; j++) {
        bool source = true;
        for (int i = 0; i < n; i++) {
            if (v[i][j] == 1) {
                source = false; 
                break;
            }
        }

        if (source) sources.push_back(j + 1);
    }

    vector<int> sinks;

    for (int i = 0; i < n; i++) {
        bool sink = true;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) {
                sink = false;
                break;
            }
        }

        if (sink) sinks.push_back(i + 1);
    }
    
    for (auto i : sources) cout << i << " ";
    cout << '\n';

    for (auto i : sinks) cout << i << " ";
    cout << '\n';

}