    #include <bits/stdc++.h>
using namespace std;
 
#define getchar_unlocked getchar
#define putchar_unlocked putchar
 
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
 
vi v (1000001, INT32_MAX);
int n;
 
int bt(int num, int op) {
    if (num == n) return 0;
    if (num > n) return INT32_MAX;
 
    // cout << num << '\n';
 
    if (num + 1 <= n && v[num + 1] == INT32_MAX) v[num + 1] = bt(num + 1, op + 1);
    if (num * 2 <= n && v[num * 2] == INT32_MAX) v[num * 2] = bt(num * 2, op + 1);
    if (num * 3 <= n && v[num * 3] == INT32_MAX) v[num * 3] = bt(num * 3, op + 1);
 
    int mn = INT32_MAX;
    if (num + 1 <= n) mn = min(mn, v[num + 1]);
    if (num * 2 <= n) mn = min(mn, v[num * 2]);
    if (num * 3 <= n) mn = min(mn, v[num * 3]);
 
    v[num] = mn + 1;
    // return mn;
 
    return v[num];
}
 
int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
 
    cout << bt(1, 0) << '\n';

    int num = 1;
    cout << 1;
    for (int i = 2; i <= n; i++) {
        if (v[i] == v[num] - 1) {
            if ((i == num + 1) || (i == num * 2) || (i == num * 3)) {
                num = i;
                cout << ' ' << num;
            }
        }
    }
    cout << '\n';
 
}