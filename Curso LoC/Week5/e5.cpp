#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    string line;
    char prev = 'a';

    bool can = true;
    for (int i = 0; i < n; i++) {
        cin >> line;
        sort(line.begin(), line.end());
        if (line[0] != line[m - 1] || line[0] == prev) {
            cout << "NO\n";
            can = false;
            break;
        }
        else prev = line[0];
    }

    if (can) {
        cout << "YES\n";
    }

  
}