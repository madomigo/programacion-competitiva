#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        map<string, pair<int,int>> m;
        cin >> n;
        if (n == 0) break;
        string a;
        char l;
        while (n--) {
            cin >> a;
            l = a[a.size() - 1];
            a.pop_back();
            //cout << a << ' ' << l << '\n';
            if (l == 'o') m[a].first++;
            else if (l == 'a') m[a].second++;
        }

        int completas = 0, incompletas = 0, sobran = 0;
        for (auto i : m) {
            if (i.second.first >= 1 && i.second.second >= 1) {
                completas++;
            }
            if (i.second.first > 1){
                sobran += i.second.first - 1;
            }
            if (i.second.second > 1) {
                sobran += i.second.second - 1;
            }
            if (i.second.first == 0) incompletas++;
            if (i.second.second == 0) incompletas++;
        }
        cout << completas << ' ' << incompletas << ' ' << sobran << '\n';
    }
}