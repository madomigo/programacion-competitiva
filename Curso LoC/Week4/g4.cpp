#include <iostream>
#include <set>
using namespace std;

int main () {
    int n;
    cin >> n;

    int num;
    set<int> a;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.insert(num);
    }

    int m;
    cin >> m;

    set<int> b;
    for (int i = 0; i < m; i++) {
        cin >> num;
        b.insert(num);
    }

    int sol = 0;
    for (auto i : a) {
        if (b.find(i) == b.end()) sol++;
    }

    for (auto i : b) {
        if (a.find(i) == a.end()) sol++;
    }
    
    cout << sol << "\n";
}