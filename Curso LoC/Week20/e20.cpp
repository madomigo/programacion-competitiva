#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    int n;
    while (t--) {
        vector<int> even, odd;
        int num;
        cin >> n;
        n = n*2;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            if (num % 2 == 0) 
                even.push_back(i);
            else    
                odd.push_back(i);
        }
        int m = n / 2;
        m--;
        int i = 0, j = 0;
        while (m--) {
            if (i + 1 < even.size()) {
                cout << even[i] << ' ' << even[i + 1] << '\n';
                i += 2;
            }
            else if (j + 1 < odd.size()) {
                cout << odd[j] << ' ' << odd[j + 1] << '\n';
                j += 2;
            }
        }
    }
}