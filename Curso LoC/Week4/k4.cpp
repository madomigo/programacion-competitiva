#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    int num;
    map<int, int> map;
    for (int i = 0; i < n; i++) {
        cin >> num;
        map[num]++;
        if (map[num] > 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }   
    }
}
