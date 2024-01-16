#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a;
    while (true) {
        cin >> n >> a;
        if (n == 0 && a == 0) break;
        vector<int> v;
        int num;
        while (n--) {
            cin >> num;
            v.push_back(num);
        }
        int mx = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (v[v.size() - 1] - v[i] >= a) v.pop_back();
            mx = max(mx, (int)v.size() - i);
        }
        cout << mx << '\n';
    }
}