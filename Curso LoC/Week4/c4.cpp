#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    string w;
    map<string, int> mapa;
    for (int i = 0; i < n; i++) {
        cin >> w;

        mapa[w]++;
    }

    int mx = 0;
    string sol;
    for (auto i : mapa) {
        if (mx < i.second) {
            mx = i.second;
            sol = i.first;
        }
        
    }
    cout << sol << "\n";
}