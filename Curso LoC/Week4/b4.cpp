#include <iostream>
#include <set>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    int num;
    set<int> a;
    set <int> b;

    for (int i = 0; i < n; i++) {
        cin >> num;
        a.insert(num);
    }
    for (int i = 0; i < m; i++) {
        cin >> num;
        b.insert(num);
    }

    for (int i : a) {
        if (b.find(i) != b.end()) {
            cout << i << " ";
        }
    }

    cout << "\n";
}