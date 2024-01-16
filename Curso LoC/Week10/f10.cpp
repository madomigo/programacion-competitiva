#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v (1000001);

int Solve (int num) {
    if (num == n) return 0;
    if (num > n) return -1;
 
 
    if (num + 1 <= n && v[num + 1] == -1) v[num + 1] = Solve(num + 1);
    if (num * 2 <= n && v[num * 2] == -1) v[num * 2] = Solve(num * 2);
    if (num * 3 <= n && v[num * 3] == -1) v[num * 3] = Solve(num * 3);
 
    int mn = INT32_MAX;
    if (num + 1 <= n) mn = min(mn, v[num + 1]);
    if (num * 2 <= n) mn = min(mn, v[num * 2]);
    if (num * 3 <= n) mn = min(mn, v[num * 3]);
 
    v[num] = mn + 1;
 
    return v[num];
} 

int main () {
    cin >> n;

    for (int i = 0; i <= n + 1; i++) {
        v[i] = -1;
    }

    cout << Solve(1) << '\n';

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