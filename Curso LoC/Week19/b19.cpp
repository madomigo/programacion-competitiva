#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    pair<int,int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    if (a.first == b.first && a.first == c.first 
            && c.second < max(b.second, a.second) && c.second > (min(b.second, a.second))) {
        cout << abs(a.second - b.second) + 2 << '\n';
    }
    else if (a.second == b.second && a.second == c.second
            && c.first < max(b.first, a.first) && c.first > (min(b.first, a.first))) {
        cout << abs(a.first - b.first) + 2 << '\n';
    }
    else cout << abs(a.second - b.second) + abs(a.first - b.first) << '\n';
}