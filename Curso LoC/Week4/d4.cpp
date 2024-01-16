#include <iostream>
#include <map>
using namespace std;

int main () {
    int n;
    cin >> n;

    map<long long, long long> map;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        map[num]++;
    }

    long long rank = 0;
    long long sol;
    for (auto i : map) {
        if (i.first * i.second > rank) {
            rank = i.first * i.second;
            sol = i.first;
        }
    }

    cout << sol << "\n";

}