#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int n;
    cin >> n;
    int sum = 0;
    int num;
    int correct = -1;
    int correct2 = -1;
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum += num;
        if (num == 0) correct2 = i;
        if (sum == 0) correct = i;
        m[sum].push_back(i);
    }
    if (correct2 != -1) {
        cout << "YES\n";
        cout << correct2 << " " << correct2 << '\n';
        return 0;
    }
    if (correct != -1) {
        cout << "YES\n";
        cout << "1 " << correct << '\n';
        return 0;
    }
    for (auto i : m)
        if (i.second.size() > 1) {
            cout << "YES\n";
            cout << i.second[0] + 1 << " " << i.second[1] << '\n';
            return 0;
        }
    cout << "NO\n";
}