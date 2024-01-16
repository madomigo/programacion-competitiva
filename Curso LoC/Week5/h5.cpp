#include <iostream>
#include <map>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    string ans[n];
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    int val[m];
    for (int i = 0; i < m; i++) {
        cin >> val[i];
    }

    int sum = 0;
    for (int j = 0; j < m; j++) {
        map<char, int> map;
        for (int i = 0; i < n; i++) {
            map[ans[i][j]]++;
        }
        int mx = 0;
        for (auto i : map) {
            if (i.second > mx) mx = i.second;
        }
        sum += val[j] * mx;
    }

    cout << sum << "\n";
}