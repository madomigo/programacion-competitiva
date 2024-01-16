#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (cin >> n) {
        vector<int> libros (n);
        for (int i = 0; i < n; i++) {
            cin >> libros[i];
        }
        sort(libros.begin(), libros.end());
        reverse(libros.begin(), libros.end());
        int ans = 0;
        for (int i = 2; i < n; i += 3) 
            ans += libros[i];
        cout << ans << '\n';
    }
}