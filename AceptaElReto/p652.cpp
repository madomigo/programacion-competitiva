#include <bits/stdc++.h>
using namespace std;
#define int long long 

int Change (string a) {
    while (a.size() < 5) a = "0" + a;
    int nA = 0;
    for (int i = 0; i < a.size(); i++) {

        if (i == 0) {
            if (a[i] > '5') nA += (6561 * (a[i] - '0' - 1));
            else  nA += (6561 * (a[i] - '0'));
        }
        if (i == 1) {
            if (a[i] > '5') nA += (729 * (a[i] - '0' - 1));
            else  nA += (729 * (a[i] - '0'));
        }
        if (i == 2) {
            if (a[i] > '5') nA += (81 * (a[i] - '0' - 1));
            else  nA += (81 * (a[i] - '0'));
        }
        if (i == 3) {
            if (a[i] > '5') nA += (9 * (a[i] - '0' - 1));
            else  nA += (9 * (a[i] - '0'));
        }
        if (i == 4) {
            if (a[i] > '5') nA += (1 * (a[i] - '0' - 1));
            else  nA += (1 * (a[i] - '0'));
        }
    }
    return nA;
}

int32_t main () {


    string a, b;
    while (cin >> a >> b) {

        int nA = Change(a);
        int nB = Change(b);

        //cout << nA << ' ' << nB << '\n';


        int n = nA * nB;
        string ans = "";
        while (n >= 9) {
            ans = to_string(n % 9) + ans;
            n /= 9;
        }
        ans = to_string(n) + ans;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] >= '5') cout << (char)(ans[i] + 1);
            else cout << ans[i];
        }
        cout << '\n';
    }
}