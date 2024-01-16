#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    while(true) {
        cin >> t;
        if (t == 0) break;
        int totalMin= INT32_MAX;
        while (t--) {
            int mn = INT32_MIN;
            int n;
            cin >> n;
            int num;
            while (n--) {
                cin >> num;
                if (num > mn) mn = num;
            }
            totalMin = min(totalMin, mn);
        }

        cout << totalMin << '\n';
    }

    
}