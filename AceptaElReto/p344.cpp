#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;
        string s;
        int nH = 0;
        int nM = 0;
        while (n--) {
            cin >> s;
            if (s[0] == 'H') nH++;
            else nM++;
            if (s[1] == 'H') nH++;
            else nM++;
        }
        if (nH == nM) cout << "POSIBLE\n";
        else cout << "IMPOSIBLE\n";
    }   
}