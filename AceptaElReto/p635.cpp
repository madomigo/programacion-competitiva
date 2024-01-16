#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int a;
    while (n--) {
        cin >> a;
        if (a % 100 != 0) cout << (a / 100) + 1 << '\n';
        else cout << (a / 100) << '\n';
    }
}