#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int n1, n2;
    int term, ans;
    while (n--) {
        ans = 0;
        cin >> n1 >> n2;
        if (n2 < n1)  term = 1e6 - n1 + n2;
        else term = n2 - n1;
        int dif;
        while (true) {
            n1 = n2;
            cin >> n2;
            if (n2 == -1) break;
            if (n2 < n1)  dif = 1e6 - n1 + n2;
            else dif = n2 - n1;
            if (dif != term){
                term = dif;
                ans++;
            }
            
        }
        cout << ans << ' ' << (n1 + term) % 1000000 << '\n';

    }
}