#include <iostream>
#include <map>
using namespace std;

int main () {
    int n;
    cin >> n;

    string s;
    map<string, int> map;
    for (int i = 0; i < n; i++) {
        cin >> s;
        map[s]++;
    }

    int mx = 0;
    string sol;
    bool can = false;
    
    for (auto i : map) {
        if (i.second > n - i.second) {
            can = true;
            cout << i.first;
            break;
        }
    }

    if (!can) cout << "NONE";

}