#include <iostream>
#include <map>
using namespace std;

int main () {
    int n;
    cin >> n;

    int num;
    int l;
    map<int, int> map;
    for (int i = 0; i < n; i++) {
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> num;
            map[num]++;
        }
    }

    for (auto i : map) {
        cout << i.first << ' ';
    }
    cout << "\n";

    for (auto i : map) {
        if (i.second == n) cout << i.first << ' ';
    }
    
    cout << "\n";
}