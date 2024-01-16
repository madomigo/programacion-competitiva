#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        vector<int> v (n + 1);
        vector<int> c (n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        int color = 1;  
        int k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] != 0) continue; 
            k = i;
            while (c[k] == 0) {
                c[k] = color;
                k = v[k];
            }
            if (c[k] == color)
                ans++;
        }
        cout << ans << '\n';
    }
}